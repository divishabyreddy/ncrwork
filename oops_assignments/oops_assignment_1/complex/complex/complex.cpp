/*Write a C++ program to add two complex numbers. The class Complex contains
three constructors.
a. One with no parameter.
b. With one parameter(Same value for real and imaginary part)
c. With two parameters.
d. A friend functions
i. One to add two complex number by taking two reference variables of
the class complex.
ii. One to multipy two complex number by taking two reference
variables of class complex*/
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>
using namespace std;
class Complex //creates a class named complex
{
	float real;
	float img;
public:
	Complex()//constructor with no parameters
	{
		real = 0;
		img = 0;
	}
	Complex(float temp)//constructor with only one parameter
	{
		real = temp;
		img = temp;
	}
	Complex(float a, float b)//constructor with two parameters
	{
		real = a;
		img = b;
	}
	friend void add(Complex &c1, Complex &c2);//friend function to add two complex numbers
	friend void multiply(Complex &c1, Complex &c2);//friend function to  multiply two complex numbers
};
//StringToFloat class 
//in this convertStringToFloat function is defined
class StringToFloat
{
public:
	//conversion is an exception when try block fails
	class conversion {};
	// convertStringToFloat function converts string to float
	float convertStringToFloat(char *temp)
	{
		float returnFloat;
		try
		{
			int length = strlen(temp);
			int iterator = 0;

			while (temp[iterator] != '\0' && (isdigit(temp[iterator]) || temp[iterator] == '.'))
			{
				iterator++;
			}
			if (temp[iterator] != '\0')
			{
				cout << "the entered input is invalid" << endl;
				throw conversion();
			}
		}
		catch (int) {};
		returnFloat = stof(temp);
		//cout << returnFloat;
		return returnFloat;
	}
};
void add(Complex &c1, Complex &c2)
{
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.img = c1.img + c2.img;
	cout << "addition is  " << temp.real << "+i" << temp.img << endl;

}
void multiply(Complex &c1, Complex &c2)
{
	Complex temp;
	temp.real = c1.real *c2.real - c1.img*c2.img;
	temp.img = c1.img *c2.real + c1.real*c2.img;
	cout << "multiplication is  " << temp.real << "+i" << temp.img << endl;
}
int main()
{
	char choice[10] = "1";
	char temp[50];
	int length = 0;
	float dummy;
	float  real_input1, real_input2, img_input1, img_input2;
	while (*choice != 3)
	{
		cout << "choose any of the following" << endl;
		cout << "1.addition of two complex numbers" << endl;
		cout << "2.multipliacation of two complex numbers" << endl;
		cout << "3.exit" << endl;
		cout << "enter your choice" << endl;
		cin >> choice;
		if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0)
		{
			if (*choice != '3')
			{
				try
				{
					StringToFloat stringToFloatObj;

					cout << "enter the real part of first complex number" << endl;
					cin >> temp;
					real_input1 = stringToFloatObj.convertStringToFloat(temp);
					cout << "enter the imaginary part of first complex number" << endl;
					cin >> temp;
					img_input1 = stringToFloatObj.convertStringToFloat(temp);
					cout << "enter the real part of second complex number" << endl;
					cin >> temp;
					real_input2 = stringToFloatObj.convertStringToFloat(temp);
					cout << "enter the imaginary part of second complex number" << endl;
					cin >> temp;
					img_input2 = stringToFloatObj.convertStringToFloat(temp);
				}
				catch (StringToFloat::conversion)
				{
					continue;
				}
				switch (*choice)
				{
				case '1':
				{
					Complex complexObject1(real_input1, img_input1);
					Complex complexObject2(real_input2, img_input2);
					add(complexObject1, complexObject2);
					break;
				}
				case '2':
				{
					Complex complexObject1(real_input1, img_input1);
					Complex complexObject2(real_input2, img_input2);
					multiply(complexObject1, complexObject2);
					break;
				}
				default:
				{
					break;
				}
				}
			}
			else
			{
				return -1;
			}

		}
		else
		{
			cout << "please enter a valid choice" << endl;
		}

	}

	return 0;
}
