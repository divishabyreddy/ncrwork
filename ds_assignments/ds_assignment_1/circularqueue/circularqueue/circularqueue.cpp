#include<iostream>
#include<stdlib.h>
using namespace std;
class queue
{
	int front;
	int rear;
	int size;
	int *queue1;
public:
	queue()
	{
		front = rear = size = 0;
	}
	void getdata(int n)
	{
		size = n;
		queue1 = new int[n];
	}
	void enqueue(int n)
	{
		if ((rear == size) && (front == 0))
			cout << "queue is full" << endl;
		else if (rear == (front-1))
		{
			cout << "queue is full" << endl;
		}
		else
		{
			queue1[rear] = n;
		}
		if (rear == size)
			rear = 0;
		else
			rear = rear + 1;
	}
	int dequeue()
	{
		int x = -999;
		if (front == rear)
			cout << "queue is empty" << endl;
		else
		{
			x = queue1[front];
		}
		if (front == size)
			front = 0;
		else
			front++;
		return x;
	}
	void display()
	{
		if (front == rear)
			cout << "queue is empty" << endl;
		else
		{
			cout << "elements which are present in the queue are" << endl;
			for (int i = front; i < rear;)
			{
				cout << queue1[i] << endl;
				if (front == size)
					i = 0;
				else
					i=front++;
			}
		}
	}
};
int main()
{
	queue q;
	int n, x, z,c;
	cout << "enter the size of the queue" << endl;
	cin >> x;
	q.getdata(x);
	cout << "choose an option" << endl;
	cout << "1.enqueue\n" << "2.dequeue\n" << "3.display\n" << endl;
	cin >> n;
	while (n <= 3 && n > 0)
	{
		switch (n)
		{
		case 1:
			cout << "enter a number to store in the queue" << endl;
			cin >> z;
			q.enqueue(z);
			break;
		case 2:
			c = q.dequeue();
			cout << "number removed is   " << c << endl;
			break;
		case 3:
			q.display();
			break;
		default:
			cout << "invalid option" << endl;
			break;
		}
		cin >> n;
	}
	system("pause");
	return 0;
}