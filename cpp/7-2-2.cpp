#include	<iostream>
#include	<string>

class Book{
private:
	std::string title;
	std::string isbn;
	int price;

public:
	Book()
		: title(0), isbn(0), price(0) {}
	Book(std::string title, std::string isbn, int price)
		: title(title), isbn(isbn), price(price) {}

	void ShowBookInfo();
};

void Book::ShowBookInfo(){
	std::cout << "Title : " << title << std::endl;
	std::cout << "ISBN : " << isbn << std::endl;
	std::cout << "Price : " << price << std::endl;

	return;
}

class EBook : public Book{
private:
	std::string drmkey;

public:
	EBook(std::string title, std::string isbn, int price, std::string drmkey)
		: Book(title, isbn, price), drmkey(drmkey) {}

	void ShowEBookInfo();
};

void EBook::ShowEBookInfo(){
	ShowBookInfo();

	std::cout << "DRMKey : " << drmkey << std::endl;

	return;	
}

int main(){
	Book book(std::string("Good C++"), std::string("555-12345-890-0"), 20000);
	book.ShowBookInfo();

	std::cout << std::endl;

	EBook ebook(std::string("Good C++ ebook") , std::string("555-12345-890-1") , 10000, std::string("fdx9w0i8kiw"));
	ebook.ShowEBookInfo();

	return 0;
}
