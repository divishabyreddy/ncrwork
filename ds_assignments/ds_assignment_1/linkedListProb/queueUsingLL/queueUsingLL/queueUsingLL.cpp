#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class list
{
	struct node *start;
public:
	list();
	void insert_last(int);
	int delete_first();
	void travel_forward();
	~list();
};
list::list()
{
	start = NULL;
}
void list::insert_last(int ele)
{
	struct node *temp, *cur;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		cur = start;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = temp;
	}
}
int list::delete_first()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "queue is empty" << endl;
	cout << "the deleted element is" << x << endl;
	return x;
}


void list::travel_forward()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}
list::~list()
{
	while (start != NULL)
	{
		struct node *temp;
		temp = start;
		start = temp->next;
		delete temp;
	}
}
int main()
{
	int choice, nodes, element, position, i;
	list sl;

	cout << endl << "Operations on a queue" << endl;
	cout << "1.add an element to the queue" << endl;
	cout << "2.Delete an element from the queue" << endl;
	cout << "3.Elements in the queue " << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	while (choice <= 3 && choice>0)
	{
		switch (choice)
		{
		case 1:
			cout << "adding an element to the queue " << endl;
			cout << "enter the number" << endl;
			cin >> element;
			sl.insert_last(element);
			break;
		case 2:
			cout << "Delete an element from the queue" << endl;
			sl.delete_first();
			break;
		case 3:
			cout << "Elements in the queue are:" << endl;
			sl.travel_forward();
			break;
		default:
			cout << "Wrong choice" << endl;
		}
		cin >> choice;
	}
	system("pause");
	return 0;
}







