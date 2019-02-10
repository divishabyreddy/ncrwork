#include<stdio.h>
#define INT_SIZE sizeof(int)       
#define INT_BITS INT_SIZE * 8 - 1  
int rotate_right(int,unsigned int);
int main()
{
	int n;
	unsigned int b;
	printf_s("enter integer number");
	scanf_s("%d", &n);
	printf_s("enter the number of positions to be shifted");
	scanf_s("%u", &b);
	n = rotate_right(n, b);
	printf_s("%d", n);
	scanf_s("%d", &n);
}
int rotate_right(int n,unsigned int b)
{
	int drp;
	b %= INT_BITS;
	while (b--)
	{
		drp = n & 1;
		n = (n >> 1)&(~(1 << INT_BITS));
		n = n | (drp << INT_BITS);
	}
	return n;
}