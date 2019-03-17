#include<stdio.h>
void dtob(int);
int main()
{
	int a;
	printf_s("enter the number between 0 and 32 to convert it into binary");
	scanf_s("%d", &a);
	dtob(a);
	//printf_s(" \n converted number is %d", res);
	scanf_s("%d", &a);
}
void dtob(int x)
{
	if (x <= 0)
		printf_s("0");
	else
	{
		dtob(x / 2);
		if (x & 1)
			printf("1");
		else
			printf_s("0");
	}
	
}