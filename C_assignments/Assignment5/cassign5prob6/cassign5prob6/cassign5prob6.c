#include<stdio.h>
int main()
{
	FILE *fp;
	char ch=' ';
	fopen_s(&fp, "new.txt", "r");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		printf_s("%c", ch);
	}
	system("pause");
	return 0;
}