/*Create objects of employee class to show the order of invocation of constructors and
destructors. Display the sizes of each of these classes and explain with comments.
a. Call by value
b. Call by reference*/
#include<iostream>
using namespace std;
class Employee
{
	int salary;
	char ch[20];
public:
	Employee()
	{
		salary = 0;
		strcpy(ch, NULL);
	}
};