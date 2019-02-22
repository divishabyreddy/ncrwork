/*Write a program to demonstrate the situation where it is necessary to write the code for copy constructor.*/

/*If we don’t define our own copy constructor, the C++ compiler creates a default copy constructor for each class which does a member-wise copy between objects.
The compiler created copy constructor works fine in general. We need to define our own copy constructor only if an object has pointers or any runtime allocation */
/*Deep copy is possible only with user defined copy constructor*/
#include<iostream>
#include<string.h>
using namespace std;
class String
{
	char *s;
	int size;
public:
	String(const char *str = NULL)
	{
		size = strlen(str);
		s = new char[size + 1];
		strcpy(s, str);
	}
	~String()
	{
		delete[] s;
	}
	String(const String& old_str)
	{
		size = old_str.size;
		s = new char[size + 1];
		strcpy(s, old_str.s);
	}
	void change(const char *str)
	{
		delete[] s;
		size = strlen(str);
		s = new char[size + 1];
		strcpy(s, str);
	}
	void print()
	{
		cout << s << endl;
	}
};
int main()
{
	String str1("abcd");
	String str2 (str1);

	str1.print();
	str2.print();

	str2.change("abcdef");

	str1.print();
	str2.print();
	return 0;
}





