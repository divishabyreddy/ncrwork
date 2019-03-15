/*Create two classes Distance1 & Distance2 that store the value of distances.
Distance1 stores distance in meters and centimeters and Distance2 stores the
distance in feet and inches. Write a program that can read values for the class
objects and add one object of Distance1 with another object of Distance2. Use a

friend function to carry out the addition operation. The object that stores the results
may be a Distance1 or Distance2 object, depending on the unit in which the result is
required.*/
#include<iostream>
#include<math.h>
using namespace std;
class Distance2;
class Distance1//creating a class of distance 1
{
	float meters;
	float centimeters;
public:
	Distance1() {};//
	Distance1(float a, float b)//parameterised constructor 
	{
		meters = a;
		centimeters = b;
	}
	friend void add(Distance1 d1, Distance2 d2);//friend function to add two distances
};
class Distance2//defining distance2 class
{
	float feet;
	float inch;
public:
	Distance2(float a, float b)//parameterised constructor
	{
		feet = a;
		inch = b;
	}
	friend void add(Distance1 d1, Distance2 d2);//function to add the two distances
};
 void add(Distance1 d1, Distance2 d2)//function to add the two distances
{
	 Distance1 temp(0,0);
	 int x;
	 x = d2.inch + d2.feet * 12;
	// cout << x;
	 temp.centimeters = d1.centimeters + x*2.54;
	 if (temp.centimeters >= 100)
	 {
		 temp.meters += (temp.centimeters) / 100;
		 temp.centimeters = (int)(temp.centimeters) % 100;
	 }
	 std::cout << "distance in meters and centi meters is"<<std::fixed  << (floor(temp.meters*1000))/1000 << "m " << temp.centimeters << "cms" << endl;


}
 int main()
 {
	 Distance1 distance1(1, 50);//object of class distance1
	 Distance2 distance2(1, 6);//object of class distance2
	 add(distance1, distance2);
	 system("pause");
	 return 0;
 }


