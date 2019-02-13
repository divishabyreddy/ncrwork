#include<stdio.h>
#include<string.h>
int main()
{
	char str[20], token[10];
	char ch = '-';
	printf_s("enter the string");
	gets(str);
	int l = strlen(str), j = 0;
	for (int i = 0; i <l; i++)
	{
		if ((str[ i]!= ch)&&(str[i]!='\0'))
		{
			token[j] = str[i];
			j++;
		}
		else
		{
			printf_s("%s\n", token);
			j = 0;
		}
		
	}
	scanf_s("%c", &ch);
	return 0;
}