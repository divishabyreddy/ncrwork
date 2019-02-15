/*Create objects of employee class to show the order of invocation of constructors and
destructors. Display the sizes of each of these classes and explain with comments.
a. Call by value
b. Call by reference*/
#include<iostream>
using namespace std;
class Employee
{
	int salary;
	int exp;
public:
	Employee()
	{
		cout << "In default constructor" << endl;
		salary = 0;
		exp = 0;
		
	}
	Employee(int a, int b)
	{
		cout << "In parameter constructor" << endl;
		salary = a;
		exp = b;
	}
	Employee(Employee e2)
	{
		cout << "In copy constructor" << endl;
		salary = e2.salary;
		exp = e2.exp;
	}
	~Employee()
	{
		cout << "In destructor" << endl;
	}
};