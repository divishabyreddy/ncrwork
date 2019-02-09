#include<stdio.h>
#include<string.h>
void expand(char*, char*);
int main()
{
	char s1[20], s2[100];
	printf_s("enter the first string");
	gets(s1);
	expand(s1, s2);
	return 0;
}
void expand(char s1[], char s2[])
{
	int l;
    char  ch2,c='-';
	static int j = 0;
	l = strlen(s1);
	for (int i = 0; i < l; i++)
	{
		if (s1[i] == c)
		{
			ch2 = s1[i + 1];
			s2[j] = s2[j-1] + 1;
			while (s2[j] != ch2)
			{
				j++;
				s2[j] = s2[j-1] + 1;
				
			}
			s2[j + 1] = s2[j] + 1;
			i++;
		}
		else
		{
			s2[j] = s1[i];
			j++;
		}
	}
	s2[j] = '\0';
	printf_s("%s", s2);
}