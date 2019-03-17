#include<stdio.h>
struct structsize
{
	int a;
	char b;
}st1;
union unionsize
{
	int a;
	char b;
}un1;
int main()
{
	printf_s("\n size of structure is %d", sizeof(st1));
	printf_s("\n size of union is %d", sizeof(un1));
	system("pause");
}