/*Define a point class, where each object represents a point in Cartesian coordinates
(x, y). Define objects of this class and calculate the distance between the 2 points
through a friend function.*/
#include<iostream>
#include<math.h>
using namespace std;
class Point
{
	float x, y;
public:
	Point()
	{
		x = y = 0;
	}
	Point(float a, float b)
	{
		x = a;
		y = b;

	}
	friend float distance(Point p1,Point p2);
	
};
float distance(Point p1, Point p2)
{
		return sqrtf((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
int main()
{
	float f;
	Point p1(2.3, 4.5), p2(4.5, 2.3);
	f=distance(p1, p2);
	cout << f << endl;
	system("pause");
	return 0;
}