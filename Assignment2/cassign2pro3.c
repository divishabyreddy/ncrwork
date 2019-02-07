#include<stdio.h>

int main()
{
	int n, fact=1;
	printf_s("enter the number");
	scanf_s("%d", &n);
	for (int i = 1; i <=n; i++)
	{
		fact = fact * i;
	}
	printf_s("factorial using iteration is %d", fact);
	fact = 1;
	fact = factorial(n);
	printf_s("factorial using recursion is %d", fact);
}
int factorial(int x)
{
	int b;
	if (x == 1)
		return 1;
	else
	b = x * factorial(x - 1);
}