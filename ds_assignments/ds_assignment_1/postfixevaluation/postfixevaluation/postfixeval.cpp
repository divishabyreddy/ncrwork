#include<iostream>
using namespace std;
class stack
{
	int top;
	int *s;
	int size;
public:
	stack()
	{
		top = -1;
		s = NULL;
	}
	void getdata(int n)
	{
		size = n;
		s = new int[n];
	}
	bool isEmpty()
	{
		return(top == -1);
	}
	bool isFull()
	{
		return(top == size - 1);
	}
	void push(int ch)
	{
		if (!(top == size - 1))
		{
			s[++top] = ch;
			
		}
		else
			cout << "stack is full" << endl;
	}
	int pop()
	{
		int x=-999;
		if (!(top == -1))
		{
			x = s[top--];
			
		}
		else
			cout << "stack is empty" << endl;
		return x;
	}
	int peek()
	{
		int x = -999;
		if (!(top == -1))
			x = s[top];
		else
			cout << "stack is empty" << endl;
		return x;
	}
	~stack()
	{
		delete s;
	}
};
int main()
{
	char str[100],ch;
	int x1=0, x2=0,x3=0;
	stack st;
	cout << "enter the size of the stack" << endl;
	int n;
	cin >> n;
	st.getdata(n);
	cout << "enter the postfix expression" << endl;
	cin >> str;
	for (int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		if (ch >= '0'&&ch <= '9')
		{
			x3 = int(ch - 48);
			st.push(x3);
			
		}
		else
		{
			switch (ch)
			{
			case '*':
				x1 = st.pop();
				x2 = st.pop();
				x3 = x1*x2;
				
				st.push(x3);
				break;
			case '/':
				x1 = st.pop();
				x2 = st.pop();
				st.push(x2/x1);
				break;
			case '+':
				x1 = st.pop();
				x2 = st.pop();
				st.push(x1+x2);
				break;
			case '-':
				x1 = st.pop();
				x2 = st.pop();
				st.push(x1-x2);
				break;
			case '%':
				x1 = st.pop();
				x2 = st.pop();

				st.push(x2%x1);
				break;
			default:
				break;
			}
		}
	}
	cout << "the result of the expression is  " << st.pop();
	system("pause");
	return 0;
}