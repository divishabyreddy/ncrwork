#include<stdio.h>
int main()
{
	float table[2][3] = { {1.1,1.2,1.3},{2.1,2.2,2.3} };
	printf_s("It is a two dimensional array storing float values\n");
	printf_s("table +1 gives the address which is %d\n", table + 1);
	printf_s("*(table+1) gives the value present which is %d\n", *(table + 1));
	printf_s("(*(table+1)+1) gives the address present which is %d\n", (*(table + 1)+1));
	printf_s("(*(table)+1) gives the address present which is %d\n", (*(table) + 1));
	printf_s("*(*(table+1)+1) gives the address present which is %d\n", *(*(table + 1) + 1));
	printf_s("*(*(table)+1) gives the address present which is %d\n", *(*(table)+1));
	printf_s("*(*(table+1)) gives the value present which is %d\n", *(*(table + 1)));
	printf_s("*(*(table+1)+1) gives the value present which is %d\n", *(*(table + 1) + 1));
	int a;
	scanf_s("%d", &a);
}