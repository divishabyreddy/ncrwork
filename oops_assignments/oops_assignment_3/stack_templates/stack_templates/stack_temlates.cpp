#include<iostream>
using namespace std;
#define SIZE 10
template<class T>
class Stack
{
	int size;
	int top;
	T *arr;
public:
	Stack() {
		size = 0;
		top = -1;
		arr = NULL;
	}
	Stack(int x)
	{
		size = x;
		top = -1;
		arr = new T[x];
	}
	~Stack()
	{
	}
	void push(T x)
	{
		try
		{
			if (top == size - 1)
			{
				cout << "stack is full\n";
				throw "can't push into the stack";
			}
			arr[++top] = x;
		}
		catch (char *s)
		{
			cout << s << endl;
		}
	}
	bool isEmpty() {

		if (top < 0) {

			return true;
		}
		return false;
	}
	bool isFull() {

		if (top >= (MAX_SIZE - 1)) {

			return true;
		}

		return false;
	}
	T pop()
	{
		try
		{
			if (top == -1)
			{
				cout << "stack is empty\n";
				throw "can't pop from the stack";
			}

			return arr[top--];
		}
		catch (char *s)
		{
			cout << s << endl;
		}
	}
	T peek()
	{
		try
		{
			if (top == -1)
			{
				cout << "stack is empty\n";
				throw "can't pop from the stack";
			}

			return arr[top];
		}
		catch (char *s)
		{
			cout << s << endl;
		}
	}
	void display() {
		for (int i = 0; i <top+1; i++) {
			cout << arr[i] << " ";
		}
	}

};
int main()
{
	int size,  input1;

	cout << "-----------stack for int elements-----------" << endl;

	cout << "enter size for stack"<<endl;
	cin >> size;
	Stack<int> s1(size);
	char choice[10] = "";
	while (1)
	{
		cout << "choose your choice:" << endl;
		cout << "1.push" << endl;
		cout << "2.pop" << endl;
		cout << "3.display" << endl;
		cin >> choice;
		if (strcmp("1", choice) == 0 || strcmp("2", choice) == 0 || strcmp("3", choice) == 0 || strcmp("4", choice) == 0)
		{
			if (*choice != '4')
			{
				switch (*choice) {
				case '1':
					cout << "enter the element to be pushed" << endl;
					cin >> input1;
					s1.push(input1);
					break;
				case '2':
					input1 = s1.pop();
					cout << "popped element is:" << endl << input1;
					break;
				case '3':
					s1.display();
					break;
				case '4':
					exit(1);
					break;
				default:
					break;
				}
			}
			else
			{
				cout << "please enter a valid choice" << endl;
			}
		}
	}
	cout << "-----------stack for float elements =============== " << endl;
	cout << "enter size for stack";
	cin >> size;
	Stack<float> s2(size);
	float input2;
	while (1) {

		cout << "choose your choice:" << endl;
		cout << "1.push" << endl;
		cout << "2.pop" << endl;
		cout << "3.display" << endl;
		cin >> op;
		if (op >= 4) {
			break;
		}
		switch (op) {
		case 1:
			cout << "enter the element to be pushed"<<endl;
			cin >> input2;
			s2.push(input1);
			break;
		case 2:
			input1 = s2.pop();
			cout << "popped element is:" <<endl<< input1;
			break;
		case 3:
			s2.display();
			break;
		}
	}

	return 0;
}