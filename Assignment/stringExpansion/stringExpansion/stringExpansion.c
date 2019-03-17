/*string expansion*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//size of the strings
#define SIZE1 20
#define SIZE2 100
//function to expand the string1 and store it in  string2
void expand(char *s1, char *s2)
{
	int i,inc;
	static int j = -1;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == '-')
		{
			if (('a' <= s1[i - 1] && s1[i - 1] <= 'z') && (!('a' <= s1[i + 1] && s1[i + 1] <= 'z')))//checking whether the input string is valid or not
			{
				printf_s("invalid input\n");
				exit(1);
			}
			if (('A' <= s1[i - 1] && s1[i - 1] <= 'Z') && (!('A' <= s1[i + 1] && s1[i + 1] <= 'Z')))
			{
				printf_s("invalid input\n");
				exit(1);
			}
			if (('0' <= s1[i - 1] && s1[i - 1] <= '9') && (!('0' <= s1[i + 1] && s1[i + 1] <= '9')))
			{
				printf_s("invalid input\n");
				exit(1);
			}
			if (('a' <= s1[i - 1] && s1[i - 1] <= 'z') || ('A' <= s1[i - 1] && s1[i - 1] <= 'Z') || ('0' <= s1[i - 1] && s1[i - 1] <= '9'))//expanding the string if it is valid
			{
				inc = 0;
				while (s2[j] != s1[i + 1])
				{
					s2[++j] = s1[i - 1] + ++inc;
				}
				i++;
			}
			else
			{
				{printf_s("invalid input\n");
				exit(1); }
			}
		}
			else
				s2[++j] = s1[i];
		}
		s2[++j] = '\0';
		printf_s("the string after the expansion is\n");
		printf_s("%s\n", s2);
	}
	int main()
	{
		int size1;
		char s1[SIZE1], s2[SIZE2];
		printf_s("enter the string\n");
		gets(s1);
		expand(s1, s2);
		system("pause");
		return 0;
	}