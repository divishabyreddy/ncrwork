/*Define polar class where each object represents a point in polar coordinates (angle
and radius). Include static data member which keeps tracking the number of active
objects of the class.*/
#include<iostream>
static int x;
using namespace std;
class Polar
{
	float angle;
	float radius;
public:
	
	Polar()
	{
		angle = 0;
		radius = 0;
		x++;
		cout << "x value is " << x << endl;
	}
	Polar(float a, float b)
	{
		angle = a;
		radius = b;
		x++;
		cout << "x value is " << x << endl;
	}
	~Polar()
	{
		x--;
		cout << "x value is " << x << endl;
	}
};
int main()
{
	Polar p1(30,5), p2(60,10), p3;
	system("pause");
	return 0;
}