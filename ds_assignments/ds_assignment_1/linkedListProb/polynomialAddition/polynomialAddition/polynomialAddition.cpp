#include<iostream>
using namespace std;
struct node
{
	int data1;
	int data2;
	struct node *next;
};
class list
{
	struct node *start;
public:
	list();
	void insert_last(int,int);
	void travel_forward();
	~list();
	friend void polyAdd(list s1, list s2, list s3);
};
list::list()
{
	start = NULL;
}
void list::insert_last(int ele1,int ele2)
{
	struct node *temp, *cur;
	temp = new node;
	temp->data1 = ele1;
	temp->data2 = ele2;
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
void list::travel_forward()
{
	struct node *cur;
	cur = start;
	cout << "output is" << endl;
	while (cur != NULL)
	{
		cout << cur->data1 << endl;
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
void polyAdd(list s1, list s2, list s3)
{
	struct node *temp,*cur;
	if (s1.start != NULL&&s2.start != NULL)
	{
		while (s1.start->next&&s2.start->next)
		{
			if (s1.start->data2 > s2.start->data2)
			{
				temp = new node;
				temp->data1 = s1.start->data1;
				temp->data2 = s1.start->data2;
				temp->next = NULL;
				if (s3.start == NULL)
					s3.start = temp;
				else
				{
					cur = s3.start;
					while (cur->next != NULL)
						cur = cur->next;
					cur->next = temp;
				}
				s1.start = s1.start->next;
			}
			else if (s1.start->data2 < s2.start->data2)
			{
				temp = new node;
				temp->data1 = s2.start->data1;
				temp->data2 = s2.start->data2;
				temp->next = NULL;
				if (s3.start == NULL)
					s3.start = temp;
				else
				{
					cur = s3.start;
					while (cur->next != NULL)
						cur = cur->next;
					cur->next = temp;
				}
				s2.start = s2.start->next;
			}
			else if (s1.start->data2 == s2.start->data2)
			{
				temp = new node;
				temp->data1 = s1.start->data1 + s2.start->data1;
				temp->data2 = s1.start->data2 + s2.start->data2;
				temp->next = NULL;
				if (s3.start == NULL)
					s3.start = temp;
				else
				{
					cur = s3.start;
					while (cur->next != NULL)
						cur = cur->next;
					cur->next = temp;
				}
				s1.start = s1.start->next;
				s2.start = s2.start->next;
			}
		}

		while (s1.start->next || s2.start->next)
		{
			if (s1.start->next)
			{
				temp = new node;
				temp->data1 = s1.start->data1;
				temp->data2 = s1.start->data2;
				temp->next = NULL;
				if (s3.start == NULL)
					s3.start = temp;
				else
				{
					cur = s3.start;
					while (cur->next != NULL)
						cur = cur->next;
					cur->next = temp;
				}
				s1.start = s1.start->next;
			}
			if (s2.start->next)
			{
				temp = new node;
				temp->data1 = s2.start->data1;
				temp->data2 = s2.start->data2;
				temp->next = NULL;
				if (s3.start == NULL)
					s3.start = temp;
				else
				{
					cur = s3.start;
					while (cur->next != NULL)
						cur = cur->next;
					cur->next = temp;
				}
				s2.start = s2.start->next;
			}
		}
		s3.travel_forward();
	}
}
int main()
{
	int choice, nodes, element1,element2, position, i;
	list s1,s2,s3;
		cout << endl << "enter the first polynomial expression" << endl;
		cout << "enter 1 if expression isn't completed" << endl;
		cin >> choice;
		while (choice == 1)
		{
			cout << "Inserting Node at Last: " << endl;
			cout << "enter the number" << endl;
			cin >> element1 >> element2;
			s1.insert_last(element1, element2);
			cin >> choice;
		}
		cout << endl << "enter the second polynomial expression" << endl;
		cout << "enter 1 if expression isn't completed" << endl;
		cin >> choice;
		while (choice == 1)
		{
			cout << "Inserting Node at Last: " << endl;
			cout << "enter the number" << endl;
			cin >> element1 >> element2;
			s2.insert_last(element1, element2);
			cin >> choice;
		}
	 polyAdd(s1,s2,s3);
	system("pause");
	return 0;
}