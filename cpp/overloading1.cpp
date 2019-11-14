#include	<iostream>
#include	<cstring>

class Complex{
private:
	double real;
	double img;
	double get_number(const char*, int, int);

public:
	Complex(double real, double img);
	Complex(const char*);

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

	Complex operator+(const char*);
	Complex operator-(const char*);
	Complex operator*(const char*);
	Complex operator/(const char*);

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

Complex::Complex(const char* str){
	double str_real = 0;
	double str_img = 0;
	int begin = 0;
	int end = strlen(str);
	int pos_i = -1;

	for(int i=0 ; i<end ; i++){
		if(str[i] == 'i'){
			pos_i = i;
			break;
		}
	}

	if(pos_i == -1){
		str_real = get_number(str, begin, end-1);
		return;
	}

	str_real = get_number(str, begin, pos_i -1);
	str_img = get_number(str, pos_i+1, end-1);

	if(pos_i >= 1 && str[pos_i-1] == '-')
		str_img *= -1;

}

Complex Complex::operator+(const char* str){
	Complex tmp(str);
	return (*this) + tmp;
}

Complex Complex::operator-(const char* str){
	Complex tmp(str);
	return (*this) - tmp;
}

Complex Complex::operator*(const char* str){
	Complex tmp(str);
	return (*this) * tmp;
}

Complex Complex::operator/(const char* str){
	Complex tmp(str);
	return (*this) / tmp;
}

double Complex::get_number(const char* str, int from, int to){
	bool minus = false;

	if(from > to)
		return 0;
	if(str[from] == '-')
		minus = true;
	if(str[from] == '-' || str[from] == '+')
		from++;

	double num = 0;
	double decimal = 1.0;

	bool integer_part = true;

	for(int i=from ; i<=to ; i++){
		if(isdigit(str[i]) && integer_part){
			num *= 10;
			num += (str[i] - '0');
		}
		else if(str[i] == '.')
			integer_part = false;
		else if(isdigit(str[i]) && !integer_part){
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else
			break;
	}

	if(minus)
		num *= -1;

	return num;
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
