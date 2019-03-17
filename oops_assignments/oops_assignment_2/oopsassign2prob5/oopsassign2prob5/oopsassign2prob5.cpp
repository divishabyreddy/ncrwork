/*Define string class with dynamic memory allocation for string. Define default
constructor, parameterized constructors, copy constructor, destructor, Overload +,
[], =, <<, >> operators. Observe the behavior of shallow copying and deep copying.*/
#include<iostream>
#include<string.h>
using namespace std;
class String
{
	int len;
	char *ch;
public:
	String()
	{
		len = 0;
		strcpy(ch, NULL);
	}
	String(int l, char c[])
	{
		s.len = l;
		ch = (char*)malloc(sizeof(char)*(s.len + 1));
		strcpy(ch, c);
	}

	String(String c)
	{
		s.len = c.len;
		ch = (char*)malloc(sizeof(char)*(s.len + 1));
		strcpy(ch, c.ch);
	}
};