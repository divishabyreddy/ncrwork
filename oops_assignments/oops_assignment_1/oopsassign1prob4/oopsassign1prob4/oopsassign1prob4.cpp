/*Write a C++ program to perform a different arithmetic operation such as addition,
subtraction, division, modulus, and multiplication using an inline function*/
#include<iostream>
using namespace std;

inline int addition(int a, int b)//function for addition 
{
	return a + b;

}

inline int subtraction(int a, int b)//function for subtraction
{
	return a - b;

}

inline int multiplication(int a, int b)//function for multiplication
{
	return a * b;

}

inline int division(int a, int b)//function for division
{
	return a / b;

}

inline int modulus(int a, int b)//function for modulus
{
	return a % b;

}
int main()
{
	int integer1, integer2;
	cout << "enter two values to perform operations" << endl;
	cin >> integer1 >> integer2;
	cout << "addition of " << integer1 << "and " << integer2 << " is  " << addition(integer1, integer2)<<endl;
	cout << "subtraction of " << integer1 << "and " << integer2 << " is  " << subtraction(integer1, integer2) << endl;
	cout << "multiplication of " << integer1 << "and " << integer2 << " is  " << multiplication(integer1, integer2) << endl;
	cout << "division of " << integer1 << "and " << integer2 << " is  " << division(integer1, integer2) << endl;
	cout << "modulus of " << integer1 << "and " << integer2 << " is  " << modulus(integer1, integer2) << endl;
	system("pause");//to stop console from closing
	return 0;
}



