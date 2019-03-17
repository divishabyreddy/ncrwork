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
		return(top == (size - 1));
	}
	void push(char ch)
	{
		if (!isFull())
			s[++top] = ch;
		else
			cout << "stack is full";
	}
	void pop()
	{
		char ch = '!';
		if (!isEmpty())
			ch = s[top--];
		else
			cout << "stack is empty";
	}
	char peek()
	{
		char ch = '!';
		if (!isEmpty())
			ch = s[top];
		else
			cout << "stack is empty";
		return ch;
	}
	void display()
	{
		for (int i = 0; i < top; i++)
		{
			cout << s[i] << endl;
		}
	}
};
int precedence(char ch)
{
	if (ch == '^')
		return 3;
	else if (ch == '/' || ch == '*')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	else
		return -1;
}
int main()
{
	int n,x;
	static int j = 0,k;
	char c[100],rev[50], res[100], ch;
	cout << "enter an expression for conversion fron infix to postfix" << endl;
	cin >> c;
	x = strlen(c);
	for (int i = x-1,k=0;i>=0 ; i--,k++)
	{
		rev[k] = c[i];
	}
	rev[k] = '\0';
	stack obj;
	cout << "enter the size of the stack" << endl;
	cin >> n;
	obj.getsize(n);
	obj.push('!');
	for (int i = 0; i < strlen(rev); i++)
	{
		if ((rev[i] <= 'z'&&rev[i] >= 'a') || rev[i] <= 'Z'&&rev[i] >= 'A')
			res[j++] = rev[i];
		else if (rev[i] == '(')
			obj.push(rev[i]);
		else if (rev[i] == ')')
		{
			while (obj.peek() != '(' && ((obj.peek()) != '!'))
			{
				char ch = obj.peek();
				obj.pop();
				res[j++] = ch;
			}
			if (obj.peek() == '(')
			{
				obj.pop();
			}
		}
		else
		{
			while (obj.peek() != '!'&&precedence(rev[i]) <= precedence(obj.peek()))
			{
				char ch = obj.peek();
				res[j++] = ch;
				obj.pop();
			}

			obj.push(rev[i]);
		}


	}
	while (obj.peek() != '!')
	{
		char ch = obj.peek();
		obj.pop();
		res[j++] = ch;
	}
	res[j] = '\0';
	x = strlen(res);
	for (int i = x-1; i >=0; i--)
	{
		cout << res[i];
	}
	system("pause");
	return 0;
}
