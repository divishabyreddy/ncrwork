#include<stdio.h>
int main()
{
	int n,a[10],sum,c=0;
	printf_s("enter the size of the array");
	scanf_s("%d", &n);
	printf_s("enter the elements of the array");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf_s("enter the sum");
	scanf_s("%d", &sum);
	for (int i = 0; i < n; i++)
	{
		c = 0;
		for (int j = i; j < n; j++)
		{
			c = c + a[j];
			if (c > sum)
				break;
			else if (c == sum)
			{
				printf_s("the range is %d and %d", i, j);
				goto suc;
			}
		}

	}
		printf_s("failure");
suc:
		printf_s("success");
		scanf_s("%d", &n);
}