#include <stdio.h>
#include<string.h>
#include <ctype.h>
#define SIZE 50
char stack[SIZE];
int top1 = -1;
//declaring postfixEval function
int postfixEval(char *);
//push1 function adds elements to the array
push1(char element)
{
	stack[++top1] = element;
}
//pop removes the element then returns the value 
char pop1()
{
	return(stack[top1--]);
}
char peek1()
{
	return(stack[top1]);
}
//"precedence" retuns the precedence value
int precedence(char element)
{
	switch (element)
	{
	case '*':
	case '/':
		return 3;
		break;
	case '+':
	case '-':
		return 2;
		break;
	case '!':
	case '(':
		return 0;
		break;

	}
}
int isOperator(char ch)
{
	if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
		return 1;
	else
		return 0;
}
//this function converts infix expression to postfix
int infixtoPostfix(char *str)
{
	
	char postfixExpression[50], k = 0;
	for (int iterator = 0; iterator <= strlen(str); iterator++)
	{
		if ((iterator == strlen(str)))
		{
			if(str[iterator - 1] != ')')
			postfixExpression[k++] = '@';
			else
			break;
			break;
		}
		
		if (isOperator(str[iterator]) || str[iterator] == '(' || str[iterator] == ')')
		{
			if ((str[iterator - 1] <= '9') && (str[iterator - 1] >= '0'))
				postfixExpression[k++] = '@';
		}
		
	
		if ((str[iterator ] <= '9') && (str[iterator] >= '0'))
			postfixExpression[k++] = str[iterator];
		else if (str[iterator] == '(')
			push1(str[iterator]);
		
		else if (str[iterator] == ')')
		{
			while (peek1() !='(' && peek1() != '!')
			{
				char ch = peek1();
				pop1();
				postfixExpression[k++] = ch;
			}
			if (peek1() == '(')
				pop1();
		}
		
	
		else
		{
			while (peek1() != '!' && (precedence(str[iterator]) <= precedence(peek1())))
			{
				char ch = peek1();
				postfixExpression[k++] = ch;
				pop1();
			}
			push1(str[iterator]);
		}
	}
	//postfixExpression[k++] = '@';
	while (top1!= -1)
		//loop stops when the end of the stack is reached
		postfixExpression[k++] = pop1();
	postfixExpression[k] = '\0';

	/*for (int i = 0; i < strlen(postfixExpression); i++)
	{
		printf_s("%c",postfixExpression[i]);
	}*/
	//postfixEval evaluates the postfix expression
	int result = postfixEval(postfixExpression);
	//retuns the result of the expression
	return result;
}
