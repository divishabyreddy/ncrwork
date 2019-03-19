#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 25
int top = -1;
char stack[MAX_SIZE];
void push(char item)//pushes element on to the stack 
{
	if (MAX_SIZE == top)
		printf_s("stack is full");
	else
		stack[++top] = item;
}
char pop()//pops the element and returns the value 
{

	if (-1 == top)
	{
		return -999;
	}

	return stack[top--];
}
char peek()//returns the value on the top of the stack
{

	if (-1 == top)
	{
		return -999;
	}

	return stack[top];
}
int balancingParanthesis(char *str)//function to check whether the symbols are balanced
{
	int length = strlen(str);
	register int i = 0;
	for (i = 0; i < length; i++)
	{
		switch (str[i])
		{
			//pushes the opening braces on to the stack 
		case '(':
		case '[':
		case '{':
			push(str[i]);
			break;
			//when closing bracket is encountered checks for the opening bracket and pops it
		case ')':
		case ']':
		case '}':
			if (((str[i] == ')') && (peek() == '(')) || ((str[i] == ']') && (peek() == '[')) || ((str[i] == '}') && (peek() == '{')))
				pop();
			break;
		default:
			break;
		}
	}
	if (-1 == top)
	{
		//printf_s("balanced exp");
		return 1;
	}
	else
	{
		return 0;
	}
}