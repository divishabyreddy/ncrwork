#include<stdio.h>
#include<math.h>
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
	int number1 = 0, number2 = 0, number3 = 0, num = 0;
	int iterator = 0, j = 0, temp = 0, k = 0;
	while (expression[iterator] != '\0')
	{
		num = 0;
		if (isdigit(expression[iterator]))
		{
			int z;
			z = iterator;
			while (expression[iterator] != '@')
				iterator++;
			k = 0;
			for (j = iterator - 1; j >= z; j--)
			{
				temp = expression[j] - 48;
				num = num + temp * pow(10, k);
				k++;
			}
			push2(num);
		}
		else
		{
			number1 = pop2();
			number2 = pop2();
			switch (expression[iterator])//to perform various operations based on the exp 
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
		iterator++;
	}

	return  pop2();//returns the result 

}
