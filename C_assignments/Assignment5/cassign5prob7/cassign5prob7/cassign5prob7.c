#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	FILE *fp;
	unsigned char ch,buf[100];
	if (argc <= 1)
	{
		printf_s("enter the correct input");
		return -1;
	}
	fopen_s(&fp,argv[1], "a+");
	if (fp == NULL)
	{
		printf_s("cannot open the file");
		return -1;
	}
	printf_s("enter the characters");
	while ((ch = getchar()) != '\n')
	{
		fputc((~ch), fp);
	} 
	rewind(fp);
	
	fgets(buf, 100, (FILE *)fp);
	printf_s("%s", buf);
	fclose(fp);
	return 0;
}