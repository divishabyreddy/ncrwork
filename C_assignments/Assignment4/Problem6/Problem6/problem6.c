#include<stdio.h>
#include<string.h>
void rev(char*,int);
int main()
{
	char s[100];
	int l;
	printf_s("enter the string");
	gets(s);
	printf_s("%s\n", s);
	rev(s, 0);
	scanf_s("%d", &l);
	return 0;
}
void rev(char*c,int x)
{
	char z;
	z = *(c + x);
	if (*(c+x) != '\0')
		rev(c, ++x);
	else
		return 0;
	
		printf_s("%c", z);
}