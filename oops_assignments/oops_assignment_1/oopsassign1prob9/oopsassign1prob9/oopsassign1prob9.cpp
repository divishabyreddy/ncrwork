/*Write a C++ program to swap two number by both call by value and call by
reference mechanism, using two functions swap_value() and swap_reference
respectively, by getting the choice from the user and executing the user’s choice by
switch-case*/
#include<iostream>
using namespace std;
void swap_value(int, int);
void swap_reference(int*, int*);
int main()
{
	int i,a,b;
	cout << "enter the values of a and b\n";
	cin >> a >> b;
	cout << "choose an option for swapping two functions\n1.call by value \n2.call by reference\n" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		swap_value(a, b);
		break;
	case 2:
		swap_reference(&a, &b);
		cout << "after swapping" << "a is " << a << " b is " << b << endl;
		break;
	default:
		cout << "invalid option" << endl;
		break;
	}
	system("pause");
	return 0;
}
void swap_value(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "after swapping a is " << a << " b is  " << b << endl;
}
void swap_reference(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}