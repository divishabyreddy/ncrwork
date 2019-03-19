#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void stringreverse(char *);
void stringcopy(char *, char *);
void stringconcatenation(char *, char *);
void stringcompare(char *, char *);
int stringlength(char *);
int main()
{
	char  stringInput[50];
	char  string2[50];
	char  choice[10];
	while (1)//loop to select a string operation
	{
		printf_s("choose an option\n 1.string reverse\n 2.string copy\n 3.string cancatenation\n 4.string compare\n5.exit\n");
		gets(choice);
		if (*choice == '1' || *choice == '2' || *choice == '3' || *choice == '4' || *choice == '5')//to check whether the given input is valid or not
		{

			{
				switch (*choice)
				{
				case '1'://case for calling stringreverse function
				{
					printf_s("Enter the first string\n");
					gets(stringInput);
					stringreverse(stringInput);
					break;
				}
				case '2'://case for calling stringcopy function
				{
					printf_s("Enter the first string\n");
					gets(stringInput);
					stringcopy(string2, stringInput);
					break;
				}
				case '3'://case for calling stringconcatenation function
				{
					printf_s("Enter the first string\n");
					gets(stringInput);
					printf_s("enter the  string that is to be concatenated to the first string\n");
					gets(string2);
					stringconcatenation(stringInput, string2);
					break;
				}
				case '4'://case for calling stringcompare function
				{
					printf_s("Enter the first string\n");
					gets(stringInput);
					printf_s("enter the second string that is to be compared to the first string\n");
					gets(string2);
					stringcompare(stringInput, string2);
					break;
				}
				case '5'://case for exit
				{
					exit(1);
					break;
				}

				default:
					break;
				}
			}
		}
		else
			printf_s("please enter a valid option\n");
	}
	return 0;
}
//for calculating the length of the string
int stringlength(char *stringInput)
{
	int iterator = 0;
	while (stringInput[iterator] != '\0')
	{
		iterator++;
	}
	return iterator;
}
//function to reverse the string
void stringreverse(char *stringInput)
{
	int length1 = 0,iterator,value;
	length1 = stringlength(stringInput);//returns the length of the string
	value = length1-1;
	char temp;
	for (iterator = 0; iterator < ((length1/2)-1); iterator++)//for performing string reverse
	{
		temp = stringInput[iterator];
		stringInput[iterator] = stringInput[value];
		stringInput[value] = temp;
		value--;
	}
	printf_s("%s\n", stringInput);
}
//function to copy one string to another
void stringcopy(char *destinationString, char *sourceString)
{
	int jiterator;
	for ( jiterator = 0; jiterator <stringlength(sourceString); jiterator++)//for copying the string
	{
		destinationString[jiterator] = sourceString[jiterator];
	}
	destinationString[jiterator] = '\0';
	printf_s("The string after copying is ");
	printf_s("%s\n", destinationString);
}
//function for string cancatenation
void stringconcatenation(char *destinationString, char *sourceString)
{
	char *temp;
	int length1, length2 = 0;
	length1 = stringlength(destinationString);
	while (sourceString[length2] != '\0')//concatenating the second string
	{
		destinationString[length1] = sourceString[length2];
		length1++;
		length2++;
	}
	destinationString[length1] = '\0';
	printf_s("The string after concatenation is ");
	printf_s("%s\n", destinationString);
	return;
}
//function for string compare
void stringcompare(char *string1, char *string2)
{
	printf_s("the value of string compare is \n");
	while (*string1 == *string2)//comparing the strings
	{
		if (*string1 == '\0' || *string2 == '\0')
			break;

		string1++;
		string2++;
	}
	if (*string1 == '\0' && *string2 == '\0')//returns 0 if the strings are equal
		printf_s("%d", 0);
	else//returns the difference of characters if the strings are unequal
		printf_s("%d\n", *string1 - *string2);
}