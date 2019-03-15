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
class Student //creates a class named student
{
	char studentName[100];
	char grade;
	int subject1, subject2, subject3;
public:
	void set_Data(char name[], int mark1, int mark2, int mark3)//sets this data into the student object
	{
		if (mark1 > 100 || mark2 > 100 || mark3 > 100 || mark1 < 0 || mark2 < 0 || mark3 < 0)
		{
			cout << "marks are not in the valid range" << endl;
			system("pause");
			exit(1);
		}
		else
		{
			strcpy_s(studentName, name);
			subject1 = mark1;
			subject2 = mark2;
			subject3 = mark3;
		}
	}
	float calculateAverage()//calculates average marks of the student
	{
		return((subject1 + subject2 + subject3) / 3);
	}
	void computeGrade()//computes the grade based on avg
	{
		float avg = 0;
		avg = calculateAverage();//the avg value returned by function is stored in avg
		if (avg > 60)
			grade = 'A';
		else if (avg > 50 && avg <= 60)
			grade = 'B';
		else if (avg > 40 && avg <= 50)
			grade = 'C';
		else
			grade = 'F';
		
	}
	void display()//displays the student details
	{
		cout << "studentName is    "<< studentName << endl;
		cout << "subject1 marks     " << subject1 << endl;
		cout << "subject2 marks    " << subject2 << endl;
		cout << "subject3 marks    " << subject3 << endl;
		cout << "grade is  " << grade << endl;
		system("pause");
	}
};
int main()
{
	Student studentObj;//creates an object of the class student
	//float avg = 0;
	cout << "the marks given should be in the range of 0 and 100" << endl;
	studentObj.set_Data("ram", 90, 90, 100);//sets the data of the object with the given values
	//avg=studentObj.calculateAverage();
	studentObj.computeGrade();
	studentObj.display(); // displays the student details
	return 0;
}