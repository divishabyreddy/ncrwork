/*Define a complex class, define default constructor, parameterized constructors, copy
constructor, destructor. Overload +, -, unary -, ++ (prefix, postfix), =, comma (,), ->,
<< and >> operators.*/
#include<iostream>
using namespace std;
class Complex
{
	int real;
	int img;
public:
	Complex()
	{
		real = 0;
		img = 0;
	}
	Complex(int a, int b)
	{
		real = a;
		img = b;
	}
	Complex(Complex &c)
	{
		real = c.real;
		img = c.img;
	}
	Complex operator+(Complex c)
	{
		Complex temp;
		temp.real = real + c.real;
		temp.img = img + c.img;
		return temp;
	}
	Complex operator-(Complex c)
	{
		Complex temp;
		temp.real = real - c.real;
		temp.img = img - c.img;
		return temp;
	}
	Complex operator-()
	{
		Complex temp;
		temp.real = -real;
		temp.img = -img ;
		return temp;
	}
	Complex operator++()
	{
		Complex temp;
		temp.real = ++real ;
		temp.img = ++img;
		return temp;
	}
	Complex operator++(int x)
	{
		Complex temp;
		temp.real = real++;
		temp.img = img++;
		return temp;
	}
	void operator=(Complex c)
	{
		Complex temp;
		real = c.real;
		img = c.img;
	}
	Complex operator,(Complex c)
	{
		return c;
	}
	friend istream &operator >> (istream &cin, Complex &c)
	{
		std::cin >> c.real;
		std::cin >> c.img;
		return cin;
	}
	friend ostream &operator <<(ostream &cout, Complex c)
	{
		std::cout << "real is " << c.real << endl;
		std::cout << "img is  " << c.img << endl;
		return cout;
	}
	Complex* operator->()
	{
		return(this);
	}
	void print_complex()
	{
		cout << real<<endl;
		cout << img << endl;
	}
};
int main()
{
	Complex c1(2, 3), c2(4, 5), c3(c2), c4, c5(3, 7),c6;
	cout << "enter values for c6";
	cin >> c6;
	c5->print_complex();
	c3 = ++c3;
	c3 = c3++;
	c4 = c1 + c2;
	cout << "c4 value is"<<endl;
	cout << c4;
	system("pause");
	return 0;
}