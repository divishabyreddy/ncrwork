#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define SIZE 50
char s[SIZE];
int top1 = -1;
//declaring postfixEval function
int postfixEval(char *);
//push1 function adds elements to the array
push1(char element)
{
	s[++top1] = element;
}
//pop removes the element then returns the value 
char pop1()
{
	return(s[top1--]);
}
//"precedence" retuns the precedence value
int precedence(char element)
{
	switch (element)
	{
		//"#" has the hieghest precedence as it indicates the end of the stack
	case '!': return 0;
		//'(' has the next highest precedence
	case '(': return 1;
		//for '+' and '-' same precedence value
	case '+':
	case '-': return 2;
		//for '*' and '/' same precedence value
	case '*':
	case '/': return 3;
	}
}
//this function converts infix expression to postfix
int infixtoPostfix(char *str)
{

	char  postfixExpression[50], ch, elem;
	int i = 0, k = 0;
	//loop is repeated until null terminating character encountered 
	push1('!');
	while ((ch = str[i++]) != '\0')
	{
		if (ch == '(') push1(ch);
		else
			if (isalnum(ch)) postfixExpression[k++] = ch;
			else
				if (ch == ')')
				{
					while (s[top1] != '(')
						postfixExpression[k++] = pop1();
					elem = pop1();
				}
				else
				{
					while (precedence(s[top1]) >= precedence(ch))
						postfixExpression[k++] = pop1();
					push1(ch);
				}
	}
	while (s[top1] != '!')
		//loop stops when the end of the stack is reached
		postfixExpression[k++] = pop1();
	postfixExpression[k] = '\0';

	//postfixEval evaluates the postfix expression
	int result = postfixEval(postfixExpression);
	//retuns the result of the expression
	return result;
}