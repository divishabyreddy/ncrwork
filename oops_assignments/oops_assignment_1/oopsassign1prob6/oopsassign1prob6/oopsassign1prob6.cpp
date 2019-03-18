/*Define a point class, where each object represents a point in Cartesian coordinates
(x, y). Define objects of this class and calculate the distance between the 2 points
through a friend function.*/
#include<iostream>
#include<math.h>
using namespace std;
class Point//creating the class point
{
	float coordinate1, coordinate2;
public:
	Point()//constructor
	{
		coordinate1 = coordinate2 = 0;
	}
	Point(float a, float b)
	{
		coordinate1 = a;
		coordinate2 = b;

	}
	friend float distance(Point p1,Point p2);//friend function to calculate the distance between two points
	
};
float distance(Point p1, Point p2)
{
		return sqrtf((p1.coordinate1 - p2.coordinate1)*(p1.coordinate1 - p2.coordinate1) + (p1.coordinate2 - p2.coordinate2)*(p1.coordinate2 - p2.coordinate2));
}
int main()
{
	float result;
	Point point1(2.3, 4.5), point2(4.5, 2.3);
	result=distance(point1, point2);
	cout <<"the distance between the points is  "<< result << endl;
	system("pause");//to stop the console from closing
	return 0;
}