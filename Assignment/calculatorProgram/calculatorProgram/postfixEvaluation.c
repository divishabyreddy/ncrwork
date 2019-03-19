#include<stdio.h>
int stack2[20];
int top2 = -1;
//pushes the element into the array 
void push2(int element)
{
	stack2[++top2] = element;
}
//pops the last element and returns it 
int pop2()
{
	return stack2[top2--];
}
//evaluates the postfix expression
int postfixEval(char *expression)
{
	char *exp;
	int number1, number2, number3, num;

	exp = expression;
	while (*exp != '\0')
	{
		if (isdigit(*exp))//for converting the character to number
		{
			num = *exp - 48;
			push2(num);
		}
		else
		{
			number1 = pop2();
			number2 = pop2();
			switch (*exp)//to perform various operations based on the exp 
			{
			case '+'://erforms addition operation
			{
				number3 = number1 + number2;
				break;
			}
			case '-'://erforms subtraction operation
			{
				number3 = number2 - number1;
				break;
			}
			case '*'://performs multilication operation
			{
				number3 = number1 * number2;
				break;
			}
			case '/'://performs division operation
			{
				number3 = number2 / number1;
				break;
			}
			}
			push2(number3);//pushes the result after operation into the array 
		}
		exp++;
	}

	return  pop2();//returns the result 

}