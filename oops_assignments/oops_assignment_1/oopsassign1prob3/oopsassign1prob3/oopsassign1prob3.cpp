/*Write a C++ program to add two complex numbers. The class Complex contains
three constructors.
a. One with no parameter.
b. With one parameter(Same value for real and imaginary part)
c. With two parameters.
d. A friend functions
i. One to add two complex number by taking two reference variables of
the class complex.
ii. One to multipy two complex number by taking two reference
variables of class complex*/
#include<iostream>
using namespace std;
class Complex //creates a class named complex
{
	float real;
	float img;
public:
	Complex()//constructor with no parameters
	{
		real = 0;
		img = 0;
	}
	Complex(float temp)//constructor with only one parameters
	{
		real = temp;
		img = temp;
	}
	Complex(float a, float b)//constructor with two parameters
	{
		real = a;
		img = b;
	}
	friend void add(Complex &c1, Complex &c2);//friend function to add two complex numbers
	friend void multiply(Complex &c1, Complex &c2);//friend function to  multiply two complex numbers
};
void add(Complex &c1, Complex &c2)
{
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	cout << "addition is  " << temp.real << "+i" << temp.img << endl;

}
void multiply(Complex &c1, Complex &c2)
{
	Complex temp;
	temp.real = c1.real *c2.real-c1.img*c2.img;
	temp.img = c1.img *c2.real+c1.real*c2.img;
	cout << "multiplication is  " << temp.real << "+i" << temp.img << endl;
}
int main()
{
	Complex complex3, complex1(5), complex2(5, 5);//cretaes objects of class complex
	add(complex2, complex1);
	multiply(complex1, complex2);
	system("pause");//stops the console from closing
	return 0;
}
	