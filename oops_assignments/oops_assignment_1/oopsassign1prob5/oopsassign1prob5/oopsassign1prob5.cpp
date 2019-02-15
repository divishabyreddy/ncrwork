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
class Distance1
{
	
	float meters;
	float cms;
public:
	Distance1() {};
	Distance1(float a, float b)
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
	Distance2(float a, float b)
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
	 if (temp.cms >= 100)
	 {
		 temp.meters += (temp.cms) / 100;
		 temp.cms = (int)(temp.cms) % 100;
	 }
	 std::cout << "distance in meters and centi meters is"<<std::fixed  << (floor(temp.meters*1000))/1000 << "m " << temp.cms << "cms" << endl;

	
}
 int main()
 {
	 Distance1 d1(1, 50);
	 Distance2 d2(1, 6);
	 add(d1, d2);
	 system("pause");
	 return 0;
 }


