/*Create two classes Distance1 & Distance2 that store the value of distances.
Distance1 stores distance in meters and centimeters and Distance2 stores the
distance in feet and inches. Write a program that can read values for the class
objects and add one object of Distance1 with another object of Distance2. Use a

friend function to carry out the addition operation. The object that stores the results
may be a Distance1 or Distance2 object, depending on the unit in which the result is
required.*/
#include<iostream>
using namespace std;
class Distance1
{
	
	float meters;
	float cms;
public:
	Distance1() {};
	Distance1(int a, int b)
	{
		meters = a;
		cms = b;
	}
	friend void add(Distance1 d1, Distance2 d2);
};
class Distance2
{
	float feet;
	float inch;
public:
	Distance2(int a, int b)
	{
		feet = a;
		inch = b;
	}
	friend void add(Distance1 d1, Distance2 d2);
};
 void add(Distance1 d1, Distance2 d2)
{
	 Distance1 temp;
	 d2.inch = d2.inch + d2.feet * 12;
	 temp.cms = d1.cms + d2.inch*2.54;
}


