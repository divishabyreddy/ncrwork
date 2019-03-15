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
	int minutes;
	int seconds;
public:
	Time()//constructor without any parameters
	{
		hours = minutes = seconds = 0;
	}
	Time(int h,int m,int s)//constructor with parameters
	{
		if (h > 24 || m > 60 || s > 60 || h < 0 || m < 0 || s < 0)
		{
			cout << "invalid input, the range is out of bounds" << endl;
			system("pause");
			exit(1);
		}
		else
		{
			hours = h;
			minutes = m;
			seconds = s;
		}
	}
	void display()//to display the time in given format
	{
		cout << hours << ":" << minutes << ":" << seconds<<endl;
	}
	Time operator+(Time t1)//for adding the two time objects and storing it in third one 
	{
		Time temp;
		temp.seconds = seconds + t1.seconds;
		temp.hours = hours + t1.hours;
		temp.minutes = minutes + t1.minutes;
		if (temp.seconds >= 60)
		{
			temp.seconds = temp.seconds - 60;
			temp.minutes++;
		}
		if (temp.minutes >= 60)
		{
			temp.minutes = temp.minutes - 60;
			temp.hours++;
		}
		return(temp);
	}
};
int main()
{
	Time time1(11, 43, 34), time2(35, 32, 32), time3;//creating objects
	cout << "time1 is ";
	time1.display();
	cout << "sum of time1 and time2 is  ";
	time3 = time1 + time2;//adding two time objects
	time3.display();
	system("pause");//to stop the console from closing
	return 0;
}