#include<iostream>
#include<stdlib.h>
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
	int balancingParanthesis(char *s)
	{
		int n;
		stack obj;
		cout << "enter the size" << endl;
		cin >> n;
		obj.getsize(n);
		int flag = 0;
		char ch;
		for (int i = 0; i < strlen(s); i++)
		{
			ch = s[i];
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
					cout << "the element popped is  " << obj.pop() << endl;
				else if (ch == '}')
				{
					flag = 1;
					break;
				}
				if (ch == ']' && obj.peek() == '[')
					cout << "the element popped is  " << obj.pop() << endl;
				else if (ch == ']')
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1)
			return 0;
		else
			return 1;
	
}