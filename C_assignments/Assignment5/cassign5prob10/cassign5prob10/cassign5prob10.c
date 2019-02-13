/*cassign5prob10*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	int i,j,k,count=0;
	char ch[50],c[50],d[50];
	fopen_s(&fp, "country.txt", "a+");
	if (fp == NULL)
	{
		printf_s("cannot open the file");
		return -1;
	}
	printf_s("choose the below options\n 1.determine capital of a specified country\n 2.Determine the country whose capital is specified\n3.Terminate the programme\n");
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		printf_s("enter the name of the country");
		scanf_s("%s", ch, 50);
		while (!feof(fp))
		{
			fscanf_s(fp, "%s", c);
			if (strcmp(c, ch) == 0)
			{
				fscanf_s(fp, "%s", c);
				printf_s("%s", c);
			}
		}
		break;
	case 2:
		printf_s("enter the name of the capital");
		scanf_s("%s", ch, 50);
		while (!feof(fp))
		{
			fscanf_s(fp, "%s", d);

			fscanf_s(fp, "%s", c);
			if (strcmp(c, ch) == 0)
			{
				printf_s("%s", d);
				break;
			}
		}
		break;
	case 3:
		printf_s("Exiting the program....\n");
		exit(0);
		break;
	default:
		printf_s("invalid input");
	}
	return 0;
}