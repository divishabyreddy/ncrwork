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
	BST();
	void insert(int);
	void delete_ele(int);
	void inorder();
	void preorder();
	void postorder();
	int findMax(struct node *);
	int findMin(struct node *);
	int height(struct node *);
	int noOfLeafNodes(struct node *);
	int noOfNonLeafNodes(struct node *);
	~BST();
};
BST::BST()
{
	start = NULL;
}
int BST::noOfLeafNodes(struct node *cur)
{
	if (cur == NULL)
		return 0;
	if (cur->left == NULL&&cur->right == NULL)
		return 1;
	return(noOfLeafNodes(cur->left)+ noOfLeafNodes(cur->right));
}
int BST::noOfNonLeafNodes(struct node *cur)
{
	if (cur == NULL)
		return 0;
	if (cur->left == NULL&&cur->right == NULL)
		return 0;
	return(noOfNonLeafNodes(cur->left) + noOfNonLeafNodes(cur->right)+1);
}
int BST::findMin(struct node *cur)
{
	if (cur != NULL)
	{
		while (cur->left != NULL)
			cur = cur->left;
		return(cur->data);
	}
	return -1;
}
int BST::findMax(struct node *cur)
{
	if (cur != NULL)
	{
		while (cur->right != NULL)
			cur = cur->right;
		return(cur->data);
	}
	return -1;
}
int BST::height(struct node *cur)
{
	if (cur == NULL)
		return -1;
	return(max(height(cur->left), height(cur->right)) + 1);
}
void BST::inorder()
{
	if (start != NULL)
		print(start);
}
void print(struct node *cur)
{
	if (cur != NULL)
	{
		print(cur->left);
		cout << cur->data << endl;
		print(cur->right);
	}
}
void BST::preorder()
{
	if (start != NULL)
		print1(start);
}
void print1(struct node *cur)
{
	if (cur != NULL)
	{
		cout << cur->data << endl;
		print(cur->left);
		print(cur->right);
	}
}
void BST::postorder()
{
	if (start != NULL)
		print2(start);
}
void print2(struct node *cur)
{
	if (cur != NULL)
	{
		print(cur->left);
		print(cur->right);
		cout << cur->data << endl;
	}
}
BST::~BST()
{
	if (start != NULL)
		delete_node(start);
}
void delete_node(struct node *cur)
{
	if (cur != NULL)
	{
		delete_node(cur->left);
		delete_node(cur->right);
		delete cur;
	}
}


