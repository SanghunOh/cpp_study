#include	<iostream>
#include	<set>
#include	<string>

template <typename T>
void print_set(std::set<T>& s){
	std::cout << "[ ";
	for(typename std::set<T>::iterator itr = s.begin() ; itr != s.end() ; itr++)
		std::cout << *itr << " ";
	std::cout << "]" << std::endl;;
}

class Todo{
	int priority;
	std::string job_desc;

public:
	Todo(int priority, std::string job_desc)
		: priority(priority), job_desc(job_desc){}

	bool operator<(const Todo& t) const{
		if(priority == t.priority)
			return job_desc < t.job_desc;
		return priority > t.priority;
	}

	friend std::ostream& operator <<(std::ostream& o, const Todo& td);
};

std::ostream& operator<<(std::ostream& o, const Todo& td){
	o << "[ 중요도: " << td.priority << "] " << td.job_desc << std::endl;
	return o;
}

int main(){
	std::set<Todo> todos;

	todos.insert(Todo(1, "농구하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그래밍"));
	todos.insert(Todo(3, "친구만나기"));
	todos.insert(Todo(2, "영화보기"));

	print_set(todos);
	std::cout << "---------------" << std::endl;
	std::cout << "if you finished work" << std::endl;
	todos.erase(todos.find(Todo(2, "수학 숙제 하기")));

	print_set(todos);
}
