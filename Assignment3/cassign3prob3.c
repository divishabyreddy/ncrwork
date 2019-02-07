#include <stdio.h>
#include <string.h>

int countSetBits(unsigned int n)
{
	unsigned int c; // the total bits set in n
	for (c = 0; n; n >>= 1)
	{
		c += n & 1;
		
	}
	return c;
}

int main(void)
{
	unsigned int n;
	printf_s("Enter a positive integer: ");
	scanf_s("%u", &n);
	printf_s("%d\n", countSetBits(n));
	scanf_s("%u", &n);
}
