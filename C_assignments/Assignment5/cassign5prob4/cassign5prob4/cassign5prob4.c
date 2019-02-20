#include<stdio.h>
int main()
{
	unsigned int i = 0x74882310;
	char *ch;
	ch = &i;
	if ((*ch) == 0x10)
		printf_s("The processor is little-endian ");
	else
		printf_s("The processor is big-endian ");
	scanf_s("%d", &i);
	return 0;
}