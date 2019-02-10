#include<stdio.h>
void main()
{
    char text[80];
    printf("Enter a string");
    scanf("%[^\n]", &text);  //scanning the whole string, including the white spaces
    int i=0,ch=0,num=0,tab=0,space=0;
	while(text[i]!='\0')
	{
	if((text[i]>=65&&text[i]<=90)||(text[i]>=97&&text[i]<=122)) 
	ch++;
	//printf("%c \n", text[i]);
	else if(text[i]>=48&&text[i]<=57)
	num++;
	else if(text[i]==9||text[i]==11)
	tab++;
	else if(text[i]==32)
	space++;
	
	 
	i++;
	}
	printf("\n  number of characters in the sentence %d",ch);
	printf("\n number of digits in the sentence %d",num);
	printf(" \n number of tabs in the sentence %d",tab);
	printf(" \n number of spaces in the sentence %d",space);
	
}