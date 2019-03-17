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
			cout << "queue is full"<<endl;
		else
		{
			queue1[rear] = n;
		}
		rear++;
	}
	int dequeue()
	{
		int x = -999;
		if (rear == front)
			cout << "queue is empty";
		else
			x = queue1[front];
		front++;
		
		return x;
	}
	void dispaly()
	{
		if (front == rear)
			cout << "queue is empty" << endl;
		else
		{
			cout << "the elements of the queue are  " << endl;
			for (int i = front; i < rear; i++)
			{
				cout << queue1[i]<<endl;
			}
		}
	}
};
int main()
{
	int n,d,x=0;
	cout << "enter the size of the queue" << endl;
	cin >> n;
	queue q;
	q.getdata(n);
	cout << "choose an option" << endl;
	cout << "1.enqueue\n" << "2.dequeue\n" << "3.display\n" << endl;
	cin >> d;
	while (d <= 3 && d > 0)
	{
		switch (d)
		{
		case 1:
			cout << "enter an element to store in  a queue" << endl;
			cin >> x;
			q.enqueue(x);
			break;
		case 2:
			x = q.dequeue();
			cout << "after performing dequeue" << endl;
			cout << x;
			break;
		case 3:
			q.dispaly();
			break;
		default:
			cout << "invalid option" << endl;
			break;
		}
		cin >> d;
	}
	system("pause");
	return 0;
}