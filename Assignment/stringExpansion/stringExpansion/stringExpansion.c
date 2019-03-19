/*string expansion*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//sizes of the strings
#define SIZE1 20
#define SIZE2 100
//function to expand the stringInput and store it in  expandedString
void expand(char *sourceString, char *destinationString)
{
	int iterator,incrementer;
	static int jiterator = -1;
	for (iterator = 0; sourceString[iterator] != '\0'; iterator++)
	{
		if (sourceString[iterator] == '-')//expanding the string when '-' is encountered 
		{
			if (('a' <= sourceString[iterator - 1] && sourceString[iterator - 1] <= 'z') && (!('a' <= sourceString[iterator + 1] && sourceString[iterator + 1] <= 'z')))//checking whether the input string is valid or not
			{
				printf_s("invalid input\n");
				exit(1);
			}
			if (('A' <= sourceString[iterator - 1] && sourceString[iterator - 1] <= 'Z') && (!('A' <= sourceString[iterator + 1] && sourceString[iterator + 1] <= 'Z')))//checking whether the input string is valid or not
			{
				printf_s("invalid input\n");
				exit(1);
			}
			if (('0' <= sourceString[iterator - 1] && sourceString[iterator - 1] <= '9') && (!('0' <= sourceString[iterator + 1] && sourceString[iterator + 1] <= '9')))//checking whether the input string is valid or not
			{
				printf_s("invalid input\n");
				exit(1);
			}
			if (('a' <= sourceString[iterator - 1] && sourceString[iterator - 1] <= 'z') || ('A' <= sourceString[iterator - 1] && sourceString[iterator - 1] <= 'Z') || ('0' <= sourceString[iterator - 1] && sourceString[iterator - 1] <= '9'))//expanding the string if the input is valid
			{
				incrementer = 0;
				while (destinationString[jiterator] != sourceString[iterator + 1])//expanding the string
				{
					destinationString[++jiterator] = sourceString[iterator - 1] + ++incrementer;
			
				}
				iterator++;
			}
			else
			{
				printf_s("invalid input\n");
				exit(1); 
			}
		}
			else
				destinationString[++jiterator] = sourceString[iterator];
		}
		destinationString[++jiterator] = '\0';
		printf_s("the string after the expansion is\n");
		printf_s("%s\n", destinationString);
	}
	int main()
	{
		char stringInput[SIZE1], expandedString[SIZE2];
		printf_s("enter the string that is to be expanded\n");
		gets(stringInput);
		expand(stringInput, expandedString);//calling the function expand
		system("pause");//to stop the console from closing
		return 0;
	}