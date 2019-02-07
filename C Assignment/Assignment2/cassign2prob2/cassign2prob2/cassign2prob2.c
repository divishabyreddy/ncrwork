#include<stdio.h>

int main()
{
	int i,a, b, d;
	printf_s("choose an option\n 1.binary to hexadecimal \n 2.hexadecimal to binary\n");
	scanf_s("%d", i);
	switch(i)
		case 1:
			printf_s("enter the binary number");
			scanf_s("%d", &b);
			btoh(b);
}