#include<stdio.h>
#include<string.h>
void deletech(char *, char);
int main()
{
	char s[20], ch;
	printf_s("enter the character to be deleted");
	scanf_s("%c", &ch);
	printf_s("enter the string");
	scanf_s("%s", s);
	deletech(s, ch);
	return 0;
}
void deletech(char s[], char ch)
{
	int l;
	l = strlen(s);
	for (int i = 0; i < l; i++)
	{
		if (s[i] == ch)
		{
			for (int j = i ; j < l; j++)
			{
				s[j] = s[j+1];
			}
			
			l = l - 1;
		}
	   
	}
	s[l] = '\0';
	printf_s("%s", s);
}