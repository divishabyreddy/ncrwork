#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *s[] = { "we will teach you how to ","Move a mountain ","Level a building ","Erase the past ","Make a million " };
	char c[50];
	int count=0;
	int l = (sizeof(s) / sizeof(s[0]));
	for (int i = 0; i < l; i++)
	{
		 
		for (int j = 0; j < strlen(s[i]); j++)
		{
			if (s[i][j] == 'e')
				count++;
		}
	}
	printf_s("the number of  'e' characters present are %d", count);
	scanf_s("%d", &count);
}