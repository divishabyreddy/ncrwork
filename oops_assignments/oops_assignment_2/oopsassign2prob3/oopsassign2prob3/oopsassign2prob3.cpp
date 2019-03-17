/*Define a class named Employee with data members empno, name, & salary and
appropriate member functions for setting and reading the data, constructors and
destructor. Create an array of 5 Employee objects, populate it with data by
overloading >> operator*/
#include<iostream>
#include<string.h>
using namespace std;
class Employee
{
	int empno;
	char name[20];
	int salary;
public:
	Employee()
	{
		empno = 0;
		strcpy(name, "/0");
		salary = 0;
	}
	void set_data()
	{
		std::cout << "empno is   " << endl;
		std::cin>> empno;
		std::cout << "name is     " << endl;
		std::cin >> name;
		std::cout << "salary is   " << endl;
		std::cin >> salary;
	}
	void read_data()
	{
		cout << "empno is   " << empno<< endl;
		cout << "name is     " << name<<endl;
		cout << "salary is   " << salary<< endl;
	}
	friend istream &operator>> (istream &cin, Employee &e1)
	{
		cin >> e1.empno;
		cin >> e1.name;
		cin >> e1.salary ;
		return cin;
	}
	~Employee()
	{
		cout << "In destructor" << endl;
	}
};
int main()
{
	Employee e1[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> e1[i];
		e1[i].read_data();
	}
	system("pause");
	return 0;
}