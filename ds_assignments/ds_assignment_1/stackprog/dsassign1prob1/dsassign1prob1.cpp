#include<iostream>
using namespace std;

struct stack
{
	int top;
	int *s;
	int size;
};
class Stack
{
	struct stack sta;
public:
	Stack()
	{
		sta.top = -1;
		sta.s = NULL;
		sta.size = 0;
	}
	void getsize(int n)
	{
		sta.size = n;
		sta.s = new int[n];
	}
	bool isFull()
	{
		return(sta.top == (sta.size - 1));
	}
	bool isEmpty()
	{
		return(sta.top == (- 1));
	}
	void push(int ele)
	{
		if (!(sta.top == (sta.size - 1)))
			sta.s[++sta.top] = ele;
		else
			cout << "stack is full" << endl;
	}
	int pop()
	{
		int x = -999;
		if (!(sta.top == (-1)))
			x = sta.s[sta.top--];
		else
			cout << "stack is empty" << endl;
		return x;
	}
	int peek()
	{
		int x = -999;
		if (!(sta.top == (-1)))
			x = sta.s[sta.top];
		else
			cout << "stack is empty" << endl;
		return x;
	}
	void display()
	{
		for (int i = 0; i <= sta.top; i++)
		{
			cout << sta.s[i]<< endl;
		}
	}
	~Stack()
	{
		delete sta.s;
	}
};
int main()
{
	int n,choice=0,x;
	Stack obj1;
	cout << "enter the size" << endl;
	cin >> n ;
	obj1.getsize(n);
	cout << "choose an option" << endl;
	cout << "1.push an element" << endl << "2.pop an element" << endl << "3.peek an element" << endl;
	cout << "4.check if the stack is full" << endl << "5.check if the stack is empty" << endl;
	cout << "6.display the elements" << endl;
	cin >> choice;
	while (choice < 7)
	{
		
		switch (choice)
		{
		case 1:
			cout << "enter the element" << endl;
			cin >> x;
			obj1.push(x);
			break;
		case 2:
			cout << "the element which is being popped is   " << obj1.pop() << endl;
			break;
		case 3:
			cout << "the element at the top is " << obj1.peek() << endl;
			break;
		case 4:
			if (!obj1.isFull())
				cout << "the stack is not full" << endl;
			else
				cout << "stack is full" << endl;
			break;
		case 5:
			if (!obj1.isEmpty())
				cout << "the stack is not empty" << endl;
			else
				cout << "stack is empty" << endl;
			break;
		case 6:
			obj1.display();
			break;
		default:
			break;
		}
		cout << "choose an option" << endl;
		cin >> choice;
	}
	
	system("pause");
	return 0;
}