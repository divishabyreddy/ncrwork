#include<stdio.h>
#include<string.h>
void replace(char *cat);
int main()
{
	char *cat = "The cat sat";
	replace(cat);
	return 0;
}
void replace(char *cat)
{
	int count=0;
	char ch = ' ';
	int l = strlen(cat);
	for (int i = 0; i < l; i++)
	{
		if (cat[i] == ch)
		{
			cat[i] = '-';
			count++;
		}
	}
	printf_s("%s", cat);
	printf_s("\n %d", count);
	scanf_s("%d", &count);
}