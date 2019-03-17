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
	int delete_last();
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

int list::delete_last()
{
	int x = -1;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
		}
		else
		{
			struct node *cur;
			cur = start;
			while (cur->next->next != NULL)
				cur = cur->next;
			x = cur->next->data;
			delete cur->next;
			cur->next = NULL;
		}
	}
	else
		cout << "list is empty" << endl;
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

	cout << endl << "Operations on singly linked list" << endl;
	cout << "1.Insert node at last" << endl;
	cout << "2.Delete last node" << endl;
	cout << "3.Travel forward" << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	while (choice <=3 && choice>0)
	{
		switch (choice)
		{
		case 1:
			cout << "Inserting Node at Last: " << endl;
			cout << "enter the number" << endl;
			cin >> element;
			sl.insert_last(element);
			break;
		case 2:
			cout << "Delete last node" << endl;
			sl.delete_last();
			break;
		case 3:
			cout << "Travelling forward" << endl;
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







