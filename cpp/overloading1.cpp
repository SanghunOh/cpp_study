#include	<iostream>

class Complex{
private:
	double real;
	double img;

public:
	Complex(double real, double img);

	Complex plus(const Complex&);
	Complex minus(const Complex&);
	Complex times(const Complex&);
	Complex divide(const Complex&);

	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator*(const Complex&);
	Complex operator/(const Complex&);
	Complex& operator=(const Complex&);
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);

	void println() const;
};

Complex::Complex(double real, double img)
	: real(real), img(img){}

Complex Complex::plus(const Complex& c){
	Complex tmp(real+c.real, img + c.img);

	return tmp;
}

Complex Complex::minus(const Complex& c){
	Complex tmp(real - c.real, img - c.img);

	return tmp;
}

Complex Complex::times(const Complex& c){
	Complex tmp(real*img - c.real*c.img, real*c.img + img*c.real);

	return tmp;
}

Complex Complex::divide(const Complex& c){
	Complex tmp((real*img + c.real*c.img)/(c.img*c.img + img*img), (img*c.real - real*c.img)/(img*img + c.img*c.img));

	return tmp;
}

Complex Complex::operator+(const Complex& c){
	Complex tmp(real + c.real, img + c.img);
	return tmp;
}

Complex Complex::operator-(const Complex& c){
	Complex tmp(real - c.real, img - c.img);
	return tmp;
}

Complex Complex::operator*(const Complex& c){
	Complex tmp(real*c.real - img*c.img, real*c.img + img*c.real);
	return tmp;
}

Complex Complex::operator/(const Complex& c){
	Complex temp((real*c.real + img*c.img) / (c.real*c.real + c.img*c.img), (img*c.real - real*c.img) / (c.real*c.real + c.img*c.img));
	return temp;
}

Complex& Complex::operator=(const Complex& c){
	real = c.real;
	img = c.img;

	return *this;
}

Complex& Complex::operator+=(const Complex& c){
	(*this) = (*this) + c;
	return *this;
}

Complex& Complex::operator-=(const Complex& c){
	(*this) = (*this) - c;
	return *this;
}

Complex& Complex::operator*=(const Complex& c){
	(*this) = (*this) * c;
	return *this;
}

Complex& Complex::operator/=(const Complex& c){
	(*this) = (*this) / c;
	return *this;
}

void Complex::println() const{
	std::cout << real << " + " << img << "i" << std::endl;
}



int main(){
	Complex a(1.0, 2.0);
	Complex b(4.0, 1.0);
	Complex c(0.0, 0.0);

	c = a*b + a/b + a + b;


	c.println();
	return 0;
}
