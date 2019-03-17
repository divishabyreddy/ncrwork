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
	void insert_first(int);
	void insert_last(int);
	void insert_after(int, int);
	void insert_before(int, int);
	int delete_first();
	int delete_last();
	void delete_spec(int);
	void travel_forward();
	void travel_backward();
	void reverse();
	~list();
	friend void print(struct node *cur);
};
list::list()
{
	start = NULL;
}
void list::insert_first(int ele)
{
		struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
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
void list:: insert_after(int x, int ele)
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
				temp->next = cur->next;
				cur->next = temp;
			}
			else
				cout << "element not found" << endl;
		}
		else
			cout << "list is empty" << endl;
	}
void list::insert_before(int x, int ele)
{
	if (start != NULL)
	{
		if (start->data == x)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = start;
			start = temp;
		}
		else
		{
			struct node *cur,*temp;
			cur = start;
			while (cur->next != NULL&&cur->next->data != x)
				cur = cur->next;
			if (cur->next != NULL)
			{
				temp = new node;
				temp->data = ele;
				temp->next = cur->next;
				cur->next = temp;
			}
			else
			{
				cout << "element not found" << endl;
			}
		}
		}
	else
		cout << "list is empty" << endl;
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
			cout << "list is empty" << endl;
		return x;
	}
	int list::delete_last()
	{
		int x = -999;
		if (start != NULL)
		{
			if (start->next = NULL)
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
	void list::delete_spec(int ele)
	{
		struct node *temp, *cur;
		if (start != NULL)
		{
			if (start->data == ele)
			{
				temp = start;
				start = temp->next;
				delete temp;
			}
			else
			{
				cur = start;
				while (cur->next != NULL&&cur->next->data != ele)
					cur = cur->next;
				if (cur->next != NULL)
				{
					temp = cur->next;
					cur->next = temp->next;
					delete temp;
				}
				else
					cout << "element not found" << endl;
			}
		}
		else
			cout << "list is empty";
		}
		void list::travel_forward()
		{
			struct node *cur;
			cur = start;
			while (cur != NULL)
			{
				cout << cur->data<<endl;
				cur = cur->next;
			}
		}
		void list::travel_backward()
		{
			if (start != NULL)
				print(start);
		}
	 void print(struct node *cur)
		{
			if (cur != NULL)
			{
				print(cur->next);
					cout << cur->data<<endl;
			}
		}
	 void list::reverse()
	 {
		 struct node *rev, *temp;
		 rev = NULL;
		 if (start != NULL)
		 {
			 if (start->next != NULL)
			 {
				 while (start != NULL)
				 {
					 temp = start;
					 start = temp->next;
					 temp->next = rev;
					 rev = temp;
				 }
				 start = rev;
			 }
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
					cout << "1.Insert Node at beginning" << endl;
					cout << "2.Insert node at last" << endl;
					cout << "3.Insert node after a position" << endl;
					cout << "4.Insert a node before a position" << endl;
					cout << "5.Delete a first Node" << endl;
					cout << "6.Delete last node" << endl;
					cout << "7.Delete specific node" << endl;
					cout << "8.Travel forward" << endl;
					cout << "9.travel backward" << endl;
					cout << "10.Reverse " << endl;
					cout << "Enter your choice : ";
					cin >> choice;
					while (choice<=10&&choice>0)
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
						sl.insert_after(position,element);
						break;
					case 4:
						cout << "Insert a node before a position " << endl;
						cout << "enter the number" << endl;
						cin >> element;
						cout << "enter the position" << endl;
						cin >> position;
						sl.insert_before(position,element);
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
						cout << "Travelling forward" << endl;
						sl.travel_forward();
						break;
					case 9:
						cout << "trwvelling backward" << endl;
						sl.travel_backward();
						break;
					case 10:
						cout << "Reverse elements of Link List" << endl;
						sl.reverse();
						break;
					default:
						cout << "Wrong choice" << endl;
					}
					cin >> choice;
				}
				system("pause");
				return 0;
			}


			




