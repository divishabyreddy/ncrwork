/*Define string class with dynamic memory allocation for string. Define default
constructor, parameterized constructors, copy constructor, destructor, Overload +,
[], =, <<, >> operators. Observe the behavior of shallow copying and deep copying.*/
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
//creates a class named string
class String
{
	char *ptr;
	int length;
public:
	String()
	{
		ptr = NULL;
		length = 0;
	}
	String(char *p, int len)//parameterised constructor
	{
		ptr = new char[len+1];
		length = len;
		strcpy_s(ptr,length+1, p);
	}
	String(const String &s)//copy constructor
	{
		length = s.length;
		ptr = new char[length + 1];
		strcpy_s(ptr, length+1 ,s.ptr);
	}
	~String()//destructor
	{
		//destructor
	}
	String operator+(String s)//function for string concatenation
	{
		String temp;
		temp.length = length + s.length;
		temp.ptr = new char[(temp.length+1)];
		strcpy_s(temp.ptr, length + 1, ptr);
	    strcat_s(temp.ptr,(temp.length+1), s.ptr);
		return temp;
	}
	char& operator[](int i)
	{
		 
		return ptr[i];
	}
	String operator=(String s)//function for string comparion
	{
		length = s.length;
		if (ptr != NULL)
			delete ptr;
		ptr = new char[(length + 1)];
		strcpy_s(ptr,length+1 ,s.ptr);
		return(*this);
	}
	friend istream& operator>> (istream &cin, String &s);
	friend ostream& operator<<(ostream &cout, String s);
	 
};
istream& operator>> (istream &cin, String &s)//function for overloading >> operator
{
	cout << "enter the lnghth of the string and enter the string";
	std::cin >>s.length;
	s.ptr = new char[(s.length + 1)];
	std::cin >>s.ptr;
	return cin;
}
ostream& operator<<(ostream &cout, String s)//function for overloading <<operator
{
	cout << "the length of the string is" << s.length << endl;
	cout << "the string is " << s.ptr << endl;
	return cout;
}
int main()
{
	String stringobj1, stringObj2, resultObj3;//creating the objects
	char choice[10]=" ";
	while (*choice != '4')
	{
		cout << "chosse an option from below" << endl;
		cout << "1.string concatenation" << endl;
		cout << "2.string copy" << endl;
		cout << "3.To modify  a position" << endl;
		cout << "4.Exit" << endl;
		cout << "enter your choice" << endl;
		cin >> choice;
		if (*choice == '1' || *choice == '2' || *choice == '3' || *choice == '4')
		{
			switch (*choice)
			{
			case '1':
			{
				cin >> stringobj1;
				cin >> stringObj2;
				resultObj3 = stringobj1 + stringObj2;
				cout << "the result of s3=s1+s2 is" << endl;
				break;
			}
			case '2':
			{
				cout << "enter the string to be copied " << endl;
				cin >> stringObj2;
				resultObj3 = stringObj2;
				cout << "the result of s3=s2 is" << endl;
				cout << resultObj3 << endl;
				break;
			}
			case '3':
			{
				char ch;
				cout << "enter the character " << endl;
				std::cin >> ch;
				stringObj2[3] = ch;
				cout << "the result after performing s2[3]=ch is" << endl;
				cout << "the element at position 3 of stringObj2 is" << endl;
				cout << stringObj2[3];
				break;
			}
			case '4':
				exit(1);
				break;
			default:
				break;
			}

		}
		cin >> choice;
	}
	/*cin >> stringobj1;
	cin >> stringObj2;
	resultObj3 = stringobj1 + stringObj2;
	cout << "the result of s3=s1+s2 is" << endl;
	cout << resultObj3;
	cout << endl;
	resultObj3 = stringObj2;
	cout << "the result of s3=s2 is" << endl;
	cout << resultObj3;
	cout << endl;
	stringObj2[3] = 'p';
	cout << "the result after performing s2[3]='p' is" << endl;
	cout << "the element at position 3 of stringObj2 is" << endl;
	cout << stringObj2[3];*/
	system("pause");
	return 0;
}
