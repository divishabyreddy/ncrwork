/*Create a class named student with fields studentName, grade, and marks of three
subjects. Class student contains the following functions:
set_Data(studentName,marks1,marks2,mark3)
Sets student data into the object
calculateAverage():
Compute average student marks
ComputeGrade()
If avg > 60 first class
If 50 < avg < 60 second class
If 40 < avg < 50 third class
Fail if any subject marks are less than 40
display(): prints student details*/
#include<iostream>
#include<string.h>
using namespace std;
class Student
{
	char studentName[100];
	char grade;
	int sub1, sub2, sub3;
public:
	void set_Data(char name[], int m1, int m2, int m3)
	{
		strcpy(studentName, name);
		sub1 = m1;
		sub2 = m2;
		sub3 = m3;

	}
	float average()
	{
		return((sub1 + sub2 + sub3) / 3);
	}
	void computeGrade(float avg)
	{
		if (avg > 60)
			grade = 'A';
		else if (avg > 50 && avg <= 60)
			grade = 'B';
		else if (avg > 40 && avg <= 50)
			grade = 'C';
		else
			grade = 'F';
		
	}
	void display()
	{
		cout << "studentName" << " " << studentName << endl;
		cout << "subject1 marks    " << sub1 << endl;
		cout << "subject2 marks    " << sub2 << endl;
		cout << "subject3 marks    " << sub3 << endl;
		cout << "grade   " << grade << endl;
	}
};
int main()
{
	Student s1;
	float avg = 0;
	s1.set_Data("ram", 90, 90, 100);
	avg=s1.average();
	s1.computeGrade(avg);
	s1.display();
	return 0;
}