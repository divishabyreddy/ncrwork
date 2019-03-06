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
	int i , k,l;
	static int j = -1;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == '-')
		{
			l = 0;
			k = i;
			while (s2[j] != s1[k + 1])
			{
				s2[++j] = s1[i-1] + ++l;
			}
			i++;
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