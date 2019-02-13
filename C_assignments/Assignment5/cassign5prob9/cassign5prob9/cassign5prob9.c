#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	int count=0;
	fopen_s(&fp, "file2.txt", "a+");
	if (fp == NULL)
	{
		printf_s("cannot open the file");
		return -1;
	}
	printf_s("enter the characters");
	while ((ch=getchar())!='\n')
	{
		
		if (('A'<=ch)&&(ch<='Z'))
			ch = ch + 32;
		else if (('a' <= ch)&& (ch <= 'z'))
			ch = ch -32;
		fputc(ch,fp);
		count++;
	}
	ftell(fp);
	fseek(fp, -count, SEEK_CUR);
	while (!feof(fp))
	{
		ch = fgetc(fp);
		printf_s("%c", ch);
	}
	ftell(fp);
	fclose(fp);
	scanf_s("%d", &count);
	return 0;
}