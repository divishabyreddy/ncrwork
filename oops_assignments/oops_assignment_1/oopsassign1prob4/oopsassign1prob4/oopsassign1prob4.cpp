/*Write a C++ program to perform a different arithmetic operation such as addition,
subtraction, division, modulus, and multiplication using an inline function*/
#include<iostream>
using namespace std;

inline int addition(int a, int b)
{
	return a + b;

}

inline int subtraction(int a, int b)
{
	return a - b;

}

inline int multiplication(int a, int b)
{
	return a * b;

}

inline int division(int a, int b)
{
	return a / b;

}

inline int modulus(int a, int b)
{
	return a % b;

}
int main()
{
	int a, b;
	cout << "enter two values to perform operations" << endl;
	cin >> a >> b;
	cout << "addition of " << a << "and " << b << "is  " << addition(a, b)<<endl;
	cout << "subtraction of " << a << "and " << b << "is  " << subtraction(a, b) << endl;
	cout << "multiplication of " << a << "and " << b << "is  " << multiplication(a, b) << endl;
	cout << "division of " << a << "and " << b << "is  " << division(a, b) << endl;
	cout << "modulus of " << a << "and " << b << "is  " << modulus(a, b) << endl;
	system("pause");
	return 0;
}



