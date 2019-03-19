#include<stdio.h>
#include<string.h>
#define SIZE 100
//declaring validate function
int validate(char *);
//declaring infixtoPostfix function
int infixtoPostfix(char *);
int main()
{
	int result;//to store the final result
	char expression[SIZE];
	printf_s("enter the exression to be evaluated\n");
	gets(expression);
	/*for (int iterator = 0; iterator < strlen(expression); iterator++)
	{
		if ((expression[iterator] <= '0'&&expression[iterator] >= '9') || expression[iterator] == '+' || expression[iterator] == '-' || expression[iterator] == '*' || expression[iterator] == '/' || expression[iterator] == '(' || expression[iterator] == ')')
		{

		}
		else
		{
			printf_s("exression is not valid\n");
			system("pause");
			exit(1);
		}
	}*/
	if (validate(expression) == 1)//to check whether the expression is valid
	{
		//printf_s("exression is valid");
		result = infixtoPostfix(expression);//calling the function infixtoPostfix
		printf_s("the result after the evaluation of the expression is %d\n", result);
	}
	system("pause");//to stop the console from closing
	return 0;
}