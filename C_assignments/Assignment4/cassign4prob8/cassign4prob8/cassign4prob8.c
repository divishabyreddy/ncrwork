#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n,l;
	char *ch[10],temp[20];
	printf_s("enter the value of number of strings");
	scanf_s("%d", &n);
	printf_s("enter the string\n");
	for (int i = 0; i < n;i++)
	{
		
		scanf_s("%s", temp);
		l = strlen(temp)+1;
		ch[i]= (char*)malloc(l*sizeof(char));
		strcpy(ch[i], temp);
	}
	for (int i = 0; i < n; i++)
	{
		printf_s("%s\n", ch[i]);
		free(ch[i]);
	}
	return 0;
}