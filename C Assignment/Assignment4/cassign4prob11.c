#include<stdio.h>
#include<string.h>
int main()
{
	char ch=' ',s[100];
	int len;
	printf_s("enter the string you want to tokenize");
	gets(s);
	printf_s("the sring is %s", s);
	printf_s("enter the character with which you want to tokenize");
	scanf_s(" %[^\n]ch", ch);
	printf_s("the sring tokenizer you enterd is ' %c'", ch);
	scanf_s("%d", &len);

}