#ifndef UTILS_H
#define UTILS_H

#include	<string>
using std::string

namespace MyExcel{
	class Vector{
		string* data;
		int capacity;
		int length;
	
	public:
		Vector(int n = 1);
		void push_back(string s);
		string operator[](int);
		void remove(int);
		int size();
		~Vector();
	}

	class Stack{
		struct Node{
			Node* prev;
			string s;

			Node(Node* prev, string s) : prev(prev), s(s) {}
		};

		Node* current;
		Node start;

	public:
		Stack();
		void push(string);
		string pop();
		string peek();
		bool is_empty();
		~Stack();
	};

	class NumStack{
		struct Node{
			Node* prev;
			double s;

			Node(Node* p
					rev, double s) : prev(prev), s(s){}
		};

		Node* current;
		Node start;

	public:
		NumStack();
		void push(double);
		double pop();
		double pop();
		bool is_empty();
		~NumStack();
	};

	class Cell{
	protected:
		int x, y;
		Table* table;

		string data;
	
	public:
		virtual string stringify();
		virtual int to_numeric();

		Cell(string, int, int, Table*);
	};

	class Table{
	protected:
		int max_row_size, max_col_size;

		Cell*** data_table;

	public:
		Table(int, int);
		~Table();

		void reg_cell(Cell*, int, int);
		int to_numeric(const string&);
		int to_numeric(int, int);
		string stringify(const string&);
		string stringify(int, int);

		virtual string print_table() = 0;
	};

	class TxtTable : public Table{
		string repeat_char(int n, char c);
		string col_num_to_str(int);
	public:
		TxtTable(int, int);
		string print_table();
	};
}
#endif

