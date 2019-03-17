#include<stdio.h>
#include<string.h>
int main()
{
	char c[10][20],temp[20];
	int n;
	printf_s("enter value of number of strings to be printed ");
	scanf_s("%d", &n);
	printf_s("enter the strings");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", c[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(strcmp(c[i],c[j])>0)
			{
				strcpy(temp, c[i]);
				strcpy(c[i], c[j]);
				strcpy(c[j], temp);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf_s("%s", c[i]);
	}
}