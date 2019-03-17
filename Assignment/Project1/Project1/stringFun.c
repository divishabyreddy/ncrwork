////stringFunctions
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#define SIZE 20
//char *Reversing(char *str, char *reversedString, int stringLen)
//{
//	int j = stringLen - 1;
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		reversedString[i] = str[j];
//		j--;
//	}//storing from reverse
//	reversedString[stringLen] = '\0';
//	return reversedString;
//}
//
//char *Copying(char *destination, char *str, int stringLen)
//{
//	for (int i = 0; str[i] != '\0'; i++)
//	{//copying from source to destination
//		destination[i] = str[i];
//	}
//	destination[stringLen] = '\0';
//	//adding nullchar to destination string
//	return destination;
//
//}
//int Comparison(char *str, char *str2, int stringLen) {
//	while (*str)
//	{
//		// if characters differ or end of second string is reached
//		if (*str != *str2)
//			break;
//		// moving to next pair of characters
//		str++;
//		str2++;
//	}
//	// return the ASCII difference
//	//converting char* to unsigned char*
//	return *(unsigned char*)str - *(unsigned char*)str2;
//}
//
//char *concatination(char *str3, char* istr, int stringLen)
//{
//	int stringLength2 = 0;
//	for (int i = 0; str3[i] != '\0'; i++)
//	{
//		//finding new string's length
//		stringLength2++;
//	}
//	int finalLength = stringLen + stringLength2;
//	char *NewString = (char *)malloc(sizeof(char)*finalLength);
//	for (int i = 0; istr[i] != '\0'; i++)
//	{//copying first string to new string
//		NewString[i] = istr[i];
//	}
//	int k = stringLen;
//
//	for (int i = 0; str3[i] != '\0'; i++)
//	{//copying second string to new string
//		NewString[k] = str3[i];
//		k++;
//	}
//
//	NewString[finalLength] = '\0';
//	return NewString;
//}
//int main() {
//	char *istr = (char *)malloc(sizeof(char)*SIZE);
//	printf("Enter a String \n");
//	scanf("%s", istr);
//	int option, stringLen = 0;
//	//finding string length
//	for (int i = 0; istr[i] != '\0'; i++)
//	{
//		stringLen++;
//	}
//
//	while (1)
//	{
//		printf("Enter your option \n");
//		printf("1.Reversing String \n 2.Copying String \n 3.Comparing two strings \n 4.Concatinating two strings \n 5.Exit \n");
//		scanf("%d", &option);
//		switch (option)
//		{
//
//		case 1:
//			printf("Reversing a string \n");
//			//dynamic allocation for reversed string
//			char *reversedString = (char *)malloc(sizeof(char)*stringLen);
//			//calling string reverse function
//			reversedString = Reversing(istr, reversedString, stringLen);
//			printf(" reversed string is %s \n", reversedString);
//			void free(reversedString);
//			break;
//
//		case 2:
//			printf("Copying a string \n");
//			char *destination = (char *)malloc(sizeof(char)*stringLen);
//
//			//function call to copy data to other string
//			printf(" copied string is %s \n", Copying(destination, istr, stringLen));
//			void free(destination);
//			break;
//
//		case 3:
//			printf("Enter a String to compare \n");
//			char *str2 = (char *)malloc(sizeof(char)*SIZE);
//			scanf("%s", str2);
//			int ret = Comparison(istr, str2, stringLen);
//			//function compares the two strings and returns integer
//			if (ret > 0)
//				printf("old string is greater than new string \n");
//			else if (ret < 0)
//				printf("old string is greater than new string \n");
//			else
//				printf("both strings are equal \n");
//			void free(str2);
//
//			break;
//
//		case 4:
//			printf("Enter a string to concatinate \n");
//			char *str3 = (char *)malloc(sizeof(char)*SIZE);
//			//input string to concatinate
//			scanf("%s", str3);
//			str3 = concatination(str3, istr, stringLen);
//			printf("\n %s \n", str3);
//			void free(str3);
//			break;
//		case 5:
//			return 0;
//
//		default:
//			printf("enter valid option \n");
//
//		}
//
//	}
//
//	void free(istr);
//
//
//	return 1;
//}
