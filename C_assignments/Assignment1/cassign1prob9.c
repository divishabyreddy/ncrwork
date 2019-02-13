#include<stdio.h>
int main()
{
	int i, j;
	int n = 1, rows;
	printf_s("enter the number of rows");
	scanf_s("%d", &rows);
	for (i = 1; i <= rows; i++)
	{
		for (j = 1; j <= (rows - i); j++)
			printf_s(" ");
		for (j = n; j >= 1; j--)
			printf_s("%d", j);
		for (j = 2; j <= n; j++)
			printf_s("%d", j);

		printf_s("\n");
		n++;
	}
	scanf_s("%d", &i);
	return 0;
}