#include<stdio.h>
#define SIZE 100
#include<string.h>
int infixtoPostfix(char *);
int main()
{
	int result;
	char expression[SIZE];
	printf_s("enter the exression that is to be evaluated\n");
	gets(expression);
	for (int iterator = 0; iterator < strlen(expression); iterator++)
	{
		if ((expression[iterator] >= '0'&&expression[iterator] <= '9') || expression[iterator] == '+' || expression[iterator] == '-' || expression[iterator] == '*' || expression[iterator] == '/' || expression[iterator] == '(' || expression[iterator] == ')')
		{

		}
		else
		{
			printf_s("exression is not valid\n");
			system("pause");
			exit(1);
		}
	}
	//printf_s("expression is valid\n");
	if (validate(expression) == 1)//to check whether the expression is valid
	{
		printf_s("expression is valid\n");
		result =infixtoPostfix(expression);//calling the function infixtoPostfix
		printf_s("the result after the evaluation of the expression is %d\n", result);
	}
	system("pause");
	return 0;
}