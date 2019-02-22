#include<iostream>
#include<string.h>
using namespace std;
class stack
{
	int top;
	int size;
	char *s;
public:
	stack()
	{
		top = -1;
		size = 0;
		s = new char[5];
		s = NULL;
	}
	void getsize(int n)
	{
		size = n;
		s = new char[n];
	}
	bool isEmpty()
	{
		return(top == -1);
	}
	bool isFull()
	{
		return(top == size - 1);
	}
	void push(char ch)
	{
		if (!(top == size - 1))
			s[++top] = ch;
		else
			cout << "stack is full" << endl;
	}
	char pop()
	{
		char x;
		if (!(top == -1))
			x = s[top--];
		else
			cout << "stack is empty" << endl;
		return x;
	}
	char peek()
	{
		char x;
		if (!(top == -1))
			x = s[top];
		else
			cout << "stack is empty" << endl;
		return x;
	}
	void display()
	{

	}
};
int main()
{
	char str[100],ch,n;
	cout << "enter the expression to check whether the symbols are balanced" << endl;
	cin >> str;
	stack obj;
	cout << "enter the size" << endl;
	cin >> n;
	obj.getsize(n);
	int flag = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		switch (ch)
		{
		case '[':
			obj.push(ch);
			break;
		case '(':
			obj.push(ch);
			break;
		case '{':
			obj.push(ch);
			break;
		default:
			break;
		}
		if (!(obj.isEmpty()))
		{
			if (ch == ')' && (obj.peek() == '('))
				cout << "the element popped is  " << obj.pop() << endl;
			else if (ch == ')')
			{
				flag = 1;
				break;
			}
		    if (ch == '}' && obj.peek() == '{')
				cout << "the element popped is  "<<obj.pop()<<endl;
			else if (ch == '}')
			{
				flag = 1;
				break;
			}
			 if (ch == ']' && obj.peek() == '[')
				cout << "the element popped is  " << obj.pop()<<endl;
			else if (ch == ']')
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1)
		cout << "symbols are not balanced" << endl;
	else
		cout << "symbols are balanced" << endl;
	system("pause");
	return 0;
}