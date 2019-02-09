#include<stdio.h>
#include<string.h>
void deletes(char*, char*);
int main()
{
	char s1[20], s2[20];
	printf_s("enter the first string ");
	gets(s1);
	printf_s("enter the second string");
	gets(s2);
	deletes(s1, s2);
	return 0;
}
void deletes(char s1[], char s2[])
{
	int l1, l2;
	l1 = strlen(s1);
	l2 = strlen(s2);
	for (int i = 0; i < l1; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			if (s1[i] == s2[j])
			{
				for (int k = i ; k < l1; k++)
				{
					s1[k] = s1[k+1];
				}
				l1 = l1 - 1;
			}
			
		}
	
		
	}
	s1[l1] = '\0';
	printf_s("%s", s1);
}