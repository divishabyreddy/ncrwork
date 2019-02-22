#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
class DLList
{
	struct node *start;
public:
	DLList();
	void insert_first(int);
	void insert_last(int);
	void insert_after(int, int);
	void insert_before(int, int);
	int delete_first();
	int delete_last();
	void delete_spec(int);
	void travel_backward();
	~DLList();
};
DLList::DLList()
{
	start = NULL;
}
void DLList::insert_first(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	temp->prev = NULL;
	if (start != NULL)
		start->prev = temp;
	start = temp;
}
void DLList::insert_last(int ele)
{
	struct node *temp, *cur;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		cur = start;
		while (cur->next != NULL)
			cur = cur->next;
		temp->prev = cur;
		cur->next = temp;
	}
}
void DLList::insert_after(int x, int ele)
{
	if (start != NULL)
	{
		struct node *cur;
		cur = start;
		while (cur != NULL&&cur->data != x)
			cur = cur->next;
		if (cur != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->prev = cur;
			temp->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = temp;
			cur->next = temp;
		}
		else
			cout << "element not found" << endl;
	}
	else
		cout << "list is empty" << endl;
}
void DLList::insert_before(int x, int ele)
{
	if (start != NULL)
	{
		struct node *cur, *temp;
		cur = start;
		while (cur->next != NULL&&cur->next->data != x)
			cur = cur->next;
		if (cur != NULL)
		{
			temp = new node;
			temp->data = ele;
			temp->prev = cur->prev;
			temp->next = cur;
			if (cur->prev != NULL)
				cur->prev->next = temp;
		}
		else
		{
			cout << "element not found" << endl;
		}
	}
	else
		cout << "list is empty" << endl;
}
int DLList::delete_first()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		start = temp->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "list is empty" << endl;
	return x;
}
int DLList::delete_last()
{
	int x = -999;
	if (start != NULL)
	{
            struct node *cur;
			cur = start;
			while (cur->next != NULL)
				cur = cur->next;
			x = cur->data;
			if (cur->prev != NULL)
				cur->prev->next = NULL;
			else
				start = NULL;
			delete cur;
	}
	else
		cout << "list is empty" << endl;
	return x;
}
void DLList::delete_spec(int ele)
{
	struct node *temp, *cur;
	if (start != NULL)
	{
		struct node *cur;
     		cur = start;
			while (cur != NULL&&cur->data != ele)
				cur = cur->next;
			if (cur != NULL)
			{
				if (cur->prev != NULL)
					cur->prev->next = cur->next;
				else
					start = cur->next;
				if (cur->next != NULL)
					cur->next->prev = cur->prev;
				delete cur;
			}
			else
				cout << "element not found" << endl;
	}
	else
		cout << "list is empty";
}
void DLList::travel_backward()
{
	struct node *cur;
	if (start != NULL)
	{
		cur = start;
		while (cur->next != NULL)
			cur = cur->next;
		while (cur != NULL)
		{
			cout << cur->data<<endl;
			cur = cur->prev;
		}
	}
}
DLList::~DLList()
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
	DLList sl;

	cout << endl << "self adjusting list" << endl;
	cout << "1.Insert Node at beginning" << endl;
	cout << "2.Insert node at last" << endl;
	cout << "3.Insert node after a position" << endl;
	cout << "4.Insert a node before a position" << endl;
	cout << "5.Delete a first Node" << endl;
	cout << "6.Delete last node" << endl;
	cout << "7.Delete specific node" << endl;
	cout << "8.Travel backward" << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	while (choice <= 8 && choice > 0)
	{
		switch (choice)
		{
		case 1:
			cout << "Inserting Node at Beginning: " << endl;
			cout << "enter the number" << endl;
			cin >> element;
			sl.insert_first(element);
			break;
		case 2:
			cout << "Inserting Node at Last: " << endl;
			cout << "enter the number" << endl;
			cin >> element;
			sl.insert_last(element);
			break;
		case 3:
			cout << "Inserting Node at a given position:" << endl;
			cout << "enter the number" << endl;
			cin >> element;
			cout << "enter the position" << endl;
			cin >> position;
			sl.insert_after(position, element);
			break;
		case 4:
			cout << "Insert a node before a position " << endl;
			cout << "enter the number" << endl;
			cin >> element;
			cout << "enter the position" << endl;
			cin >> position;
			sl.insert_before(position, element);
			break;
		case 5:
			cout << "Delete a first node: " << endl;
			sl.delete_first();
			break;
		case 6:
			cout << "Delete last node" << endl;
			sl.delete_last();
			break;
		case 7:
			cout << "delete specific node " << endl;
			cout << "enter the number" << endl;
			cin >> element;
			sl.delete_spec(element);
			break;
		case 8:
			cout << "Travelling backward" << endl;
			sl.travel_backward();
			break;
		default:
			cout << "Wrong choice" << endl;
		}
		cout << "Enter your choice : ";
		cin >> choice;
	}
	system("pause");
	return 0;
}







