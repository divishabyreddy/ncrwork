#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
class BST
{
	struct node *start;
public:
	BST()
	{
		start = NULL;
	}
	node* insert(int,node*);
	node* delete_ele(int,node*);
	void inOrder();
	void preOrder();
	void postOrder();
	int findMax(node *);
	int findMin(node *);
	int height(node *);
	node *point();
	int noOfLeafNodes(node *);
	int noOfNonLeafNodes(node *);
	~BST();
};
int BST::noOfLeafNodes(node *cur)
{
	if (cur == NULL)
		return 0;
	else if (cur->left == NULL&&cur->right == NULL)
		return 1;
	return(noOfLeafNodes(cur->left)+ noOfLeafNodes(cur->right));
}
int BST::noOfNonLeafNodes(node *cur)
{
	if (cur == NULL)
		return 0;
	else if (cur->left == NULL&&cur->right == NULL)
		return 0;
	return(noOfNonLeafNodes(cur->left) + noOfNonLeafNodes(cur->right)+1);
}
int BST::findMin(node *cur)
{
	if (cur != NULL)
	{
		while (cur->left != NULL)
			cur = cur->left;
		return(cur->data);
	}
	return -1;
}
int BST::findMax(node *cur)
{
	if (cur != NULL)
	{
		while (cur->right != NULL)
			cur = cur->right;
		return(cur->data);
	}
	return -1;
}
int BST::height(node *cur)
{
	if (cur == NULL)
		return -1;
	return(max(height(cur->left), height(cur->right)) + 1);
}
void print(node *cur)
{
	if (cur != NULL)
	{
		print(cur->left);
		cout << cur->data<<endl;
		print(cur->right);
	}
}
void BST::inOrder()
{
	if (start != NULL)
		print(start);
}
void print1(node *cur)
{
	if (cur != NULL)
	{
		cout << cur->data << endl;
		print1(cur->left);
		print1(cur->right);
	}
}
void BST::preOrder()
{
	if (start != NULL)
		print1(start);
}
void print2(node *cur)
{
	if (cur != NULL)
	{
		print2(cur->left);
		print2(cur->right);
		cout << cur->data << endl;
	}
}
void BST::postOrder()
{
	if (start != NULL)
		print(start);
}
void delete_node(node *cur)
{
	if (cur != NULL)
	{
		delete_node(cur->left);
		delete_node(cur->right);
		delete_node(cur);
	}
}
BST::~BST()
{
	if (start != NULL)
		delete_node(start);
}
node* BST::insert(int ele, node *cur)
{
	if (cur == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->right = NULL;
		temp->left = NULL;
		return temp;
	}
	else
	{
		if (ele < cur->data)
			cur->left = insert(ele, cur->left);
		else
			cur->right = insert(ele, cur->right);
		return cur;
	}
}
node* BST::delete_ele(int ele, node *cur)
{
	if (cur != NULL)
	{
		if (ele < cur->data)
			cur->left = delete_ele(ele, cur->left);
		else if (ele > cur->data)
			cur->right = delete_ele(ele, cur->right);
		else
		{
			if (cur->left != NULL&&cur->right != NULL)
			{
				cur->data = findMax(cur->left);
				cur->left = delete_ele(cur->data, cur->left);
			}
			else
			{
				struct node *temp;
				temp = cur;
				if (cur->left == NULL)
					cur = cur->right;
				else
					cur = cur->left;
				delete temp;
			}
		}
	}
	return cur;
}
node *BST::point()
{
	return start;
}
int main()
{
	BST b1;
	int choice,element;
	struct node *cur;
	cur = b1.point();
	cout << "choose an option\n" << endl;
	cout << "1.Insert an element\n" << "2.Delete an element\n" <<"3.Display the elements\n"<< endl;
	cin >> choice;
	while (choice < 4)
	{
		switch (choice)
		{
		case 1:
			cout << "Enter the value of the element" << endl;
			cin >> element;
			b1.insert(element, cur);
			break;
		case 2:
			cout << "Enter the value of the element to be deleted\n" << endl;
			cin >> element;
			b1.delete_ele(element, cur);
			break;
		case 3:
			cout << "The elements in the tree are\n" << endl;
			b1.inOrder();
			break;
		default:
			cout << "invalid option\n" << endl;
		}
		cin >> choice;
	}
	system("pause");
	return 0;
}