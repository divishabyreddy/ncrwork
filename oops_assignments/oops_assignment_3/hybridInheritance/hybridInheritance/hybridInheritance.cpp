#include<iostream>//bits/stdc++.h
#include<string>
using namespace std;
class person
{
public:
	string name;
	int age;
	person()
	{
		name = "samar";
		age = 25;
	}
	void displayPerson()
	{
		cout << "name: " <<name << " " << "age:" << age << endl;
	}
};

class physique : virtual public person
{
public:
	int height;
	int weight;
	physique()
	{
		height = 6;
		weight = 75;
	}
	void displayPhysique()
	{

		cout << "the person height and weight are " << height << " feet " << weight <<" kgs"<< endl;
	}
};
class family : virtual public person
{
public:
	int numChild;
	string surname;
	family()
	{
		numChild = 2;
		surname = "byreddy";
	}
	void displayFamily()
	{
		cout << "the number of children are " << numChild << " and surname is " << surname << endl;    	
	}
};
class employee : public physique, public family
{
public:
	int empno;
	int salary;
	employee()
	{
		empno = 10;
		salary = 50000;
	}
	void displayEmp()
	{
		displayPerson();
		displayPhysique();
		displayFamily();
		cout << "the employee number is " << empno << " salary is " << salary << endl;
	}
};
int main()
{
	employee empObj;

	empObj.displayEmp();
	system("pause");
	return 0;
}