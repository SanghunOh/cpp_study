#include	<iostream>
#include	<string>

class Employee{
	std::string name;
	int age;
	std::string position;
	int rank;

public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}

	Employee(const Employee& employee){
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	Employee(){}

	void print_info(){
		std::cout << name << "(" << position << ", " << age << ") ==> " << calculate_pay() << std::endl;
	}

	int calculate_pay(){
		return 200 + rank* 50;
	}
};

class Manager{
	std::string name;
	int age;
	std::string position;
	int rank;
	int year_of_service;

public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
		: name(name), age(age), position(position), rank(rank), year_of_service(year_of_service) {}
	Manager(const Manager& t){
		name = t.name;
		age = t.age;
		position = t.position;
		rank = t.rank;
		year_of_service = t.year_of_service;
	}

	Manager(){}

	int calculate_pay(){
		return 200 + rank*50 + 5*year_of_service;
	}

	void print_info(){
		std::cout << name << "(" << position << ", " << age << ") ==> " << calculate_pay() << std::endl;
	}
};

class EmployeeList{
	int alloc_employee;
	int current_employee;
	int current_manager;

	Employee** employee_list;
	Manager** manager_list;

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee){
		employee_list = new Employee*[alloc_employee];
		manager_list = new Manager*[alloc_employee];

		current_employee = 0;
		current_manager = 0;
	}

	void add_employee(Employee* employee){
		if(current_employee >= alloc_employee){
			Employee** temp;
			temp = employee_list;

			alloc_employee *= 2;
			employee_list = new Employee*[alloc_employee];

			for(int i=0 ; i<current_employee ; i++){
				employee_list[i] = new Employee(*(temp[i]));
			}

			for(int i=0 ; i<current_employee ; i++)
				delete temp[i];
			delete [] temp;
		}

		employee_list[current_employee] = employee;
		current_employee++;
	}

	void add_manager(Manager* manager){
		if(current_manager >= alloc_employee){
			Manager** temp;
			temp = manager_list;

			manager_list = new Manager*[alloc_employee*2];
			alloc_employee *= 2;

			for(int i=0 ; i<current_manager ; i++)
				manager_list[i] = temp[i];
			for(int i=0 ; i<current_manager ; i++)
				delete temp[i];
			delete [] temp;
		}

		manager_list[current_manager] = manager;
		current_manager++;
	}

	int current_employee_num(){
		return current_employee + current_manager;
	}

	int alloc_employee_num(){
		return alloc_employee;
	}

	void print_employee_info(){
		int total_pay = 0;

		for(int i=0 ; i<current_employee ; i++){
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}

		std::cout << "total pay is " << total_pay << std::endl;
	}

	~EmployeeList(){
		for(int i=0 ; i<current_employee ; i++){
			delete employee_list[i];
		}
		for(int i=0 ; i<current_manager ; i++)
			delete manager_list[i];
		delete [] manager_list;
		delete [] employee_list;
	}
};

int main(){
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
	emp_list.add_manager(new Manager("유재석", 41, "평사원", 7, 10));
	emp_list.add_manager(new Manager("정준하", 43, "평사원", 4, 5));
	emp_list.add_manager(new Manager("박명수", 43, "평사원", 5, 3));
	emp_list.add_employee(new Employee("정형돈", 36, "평사원", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	std::cout << emp_list.alloc_employee_num() << std::endl;
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	std::cout << emp_list.alloc_employee_num() << std::endl;
	
	emp_list.print_employee_info();

	return 0;
}
