/*Create a class called Time that has separate int data members for hours, minute, and
seconds. One constructor should initialize the data to 0, and another should
initialize it to fixed values. A member function should display it in 11:43:34 format.
Another member function should add two objects of type Time passed as
arguments. A main() program should create two initialized Time object and one that
isn't initialized. Then it should add the two initialized values together, leaving the
result in the third time variable. Finally, it should display the value of this third
variable.*/
#include<iostream>
using namespace std;
class Time {
	int hours;
	int mins;
	int sec;
public:
	Time()
	{
		hours = mins = sec = 0;
	}
	Time(int h,int m,int s)
	{
		hours = h;
		mins = m;
		sec = s;
	}
	void display()
	{
		cout << hours << ":" << mins << ":" << sec<<endl;
	}
	Time operator+(Time t1)
	{
		Time temp;
		temp.sec = sec + t1.sec;
		temp.hours = hours + t1.hours;
		temp.mins = mins + t1.mins;
		if (temp.sec >= 60)
		{
			temp.sec = temp.sec - 60;
			temp.mins++;
		}
		if (temp.mins >= 60)
		{
			temp.mins = temp.mins - 60;
			temp.hours++;
		}
		return(temp);
	}
};
int main()
{
	Time t1(11, 43, 34), t2(12, 32, 32), t3;
	t1.display();
	t3 = t1 + t2;
	t3.display();
	system("pause");
	return 0;
}