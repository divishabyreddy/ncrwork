#include<stdio.h>
#include<string.h>
void stringreverse(char *);
void stringcopy(char *, char *);
void stringconcatenation(char *, char *);
void stringcompare(char *, char *);
int stringlength(char *);
int main()
{
	char  str[50];
	char  str2[50];
	int   choice;
	printf_s("Enter the first string\n");
	gets(str);
	printf_s("choose an option\n 1.string reverse\n 2.string copy\n 3.string cancatenation\n 4.string compare\n");
	scanf_s("%d", &choice);
	while (choice <= 4 && choice>0)
	{
		switch (choice)
		{
		case 1:
			stringreverse(str);
			break;
		case 2:
			stringcopy(str2, str);
			break;
		case 3:
	        printf_s("enter the  string that is to be concatenated to the first string\n");
	        scanf_s("%s",str2,50);
			stringconcatenation(str, str2);
			break;
		case 4:
			printf_s("enter the second string that is to be compared to the first string\n");
			scanf_s("%s", str2, 50);
			stringcompare(str, str2);
			break;
		}
		printf_s("choose an option\n 1.string reverse\n 2.string copy\n 3.string cancatenation\n 4.string compare\n");
		scanf_s("%d", &choice);
	}
	if (!(choice <= 4 && choice > 0))
		printf_s("invalid option");
	free(str);
	free(str2);
	return 0;
}
//for calculating the length of the string
int stringlength(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
//function to reverse the string
void stringreverse(char *str)
{
	char *str3;
	int i , j = 0;//for length of the strings
	i = stringlength(str);
	str3 = (char*)malloc(i * sizeof(char));
	for (i = i - 1; i >= 0; i--)
	{
		str3[j++] = str[i];
	}
	str3[j] = '\0';
	printf_s("%s\n", str3);
	free(str3);
}
//function to copy one string to another
void stringcopy(char *str2, char *str)
{
	int j;
	for ( j = 0; j <stringlength(str); j++)
	{
		str2[j] = str[j];
	}
	str2[j] = '\0';
	printf_s("The string after copying is ");
	printf_s("%s\n", str2);
}
//function for string cancatenation
void stringconcatenation(char *str, char *str2)
{
	char *temp;
	int i , j ;//for length of the strings
	i = stringlength(str);
	j = stringlength(str2);
	temp = str;
	str = (char *)malloc(sizeof(char)*(i + j + 1));
	j =i= 0;
	while (temp[i] != '\0')//storing the string value from temp
	{
		str[i] = temp[i];
		i++;
	}
	while (str2[j] != '\0')//concatenating the second string
	{
		str[i] = str2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	printf_s("%s\n", str);
	free(str);
}
//function for string compare
void stringcompare(char *str, char *str2)
{
	while (*str == *str2)
	{
		if (*str == '\0' || *str2 == '\0')
			break;

		str++;
		str2++;
	}
	if (*str == '\0' && *str2 == '\0')
		printf_s("%d", 0);
	else
		printf_s("%d\n", *str - *str2);
}