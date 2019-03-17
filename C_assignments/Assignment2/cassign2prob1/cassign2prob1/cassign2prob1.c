#include<stdio.h>
#include<math.h>
int btod(int);
int dtob(int);
int main()
{
	int b;
	int  n, i;
	printf_s("choose the options.\n 1.binary to decimal \n 2.decimal to binary\n");
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		printf_s("enter the binary number");
		scanf_s("%d", &b);
		n = btod(b);
		printf_s("the decimal equivalent is %d", n);
		scanf_s("%d", &n);
		break;
	case 2:
		printf_s("enter the decimal number");
		scanf_s("%d", &b);
		n = dtob(b);
		printf_s("the binary equivalent is %d", n);
		scanf_s("%d", &n);
		break;
	default:
		printf_s("invalid option");
		break;
	}
			return 0;
}
int btod(int x)
{
	int r, q, a=0,sum=0;
	q = x;
	while (q != 0)
	{
		r = q % 10;
		sum = sum + r*pow(2, a);
		a++;
		q = q / 10;
	}
	return sum;
}
int dtob(int x)
{
	int r, q, sum = 0,a=0;
	q = x;
	while (q != 0)
	{
		r = q % 2;
		sum = r*pow(10, a) + sum;
		a++;
		q = q / 2;
	}
	return sum;
}