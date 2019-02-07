#include<stdio.h>
int main()
{
	int hex,ch,type,num;
	int flag = 0xffff;
	printf_s("enter an hexadecimal number");
	scanf_s("%X", &hex);
	printf_s("choose any of the follwing options \n 1. hexa decimal equivalent of 1's complement \n 2.masking operation \n 3.bit shifting operation \n 4.exit \n");
	scanf_s("%d", &ch);
	switch (ch)
	{
	case 1:

		printf_s("%X", flag- hex);
		break;
	case 2:
		printf_s("which type of masking operation do you want to perform \n 1.bitwiseAND \n 2.bitwise ExOR \n 3. bitwise OR");
		scanf_s("%d", &type);
		printf_s("enter the hexa decimal number with which masking operation has to be performed");
		scanf_s("%x", &num);
		if (type == 1)
		{
			printf("%x", hex&num);
		}
		else if (type == 2)
		{
			printf_s("%x", hex^num);

		}
		else if (type == 3)
		{
			printf_s("%x", hex|num);

		}
		else
		{
			printf_s("invalid option");
		}
		break;
	case 3:
		printf_s("which type of shiftin  operation do you want to perform \n 1.leftshift \n 2.right shift \n ");
		scanf_s("%d", &type);
		printf_s("how many bits do you want  to shift");
		scanf_s("%d", &num);
		if (type == 1)
		{
			printf("%x", hex<<num);
		}
		else if (type == 2)
		{
			printf_s("%x", hex>>num);

		}
		else if (type == 3)
		{
			printf_s("invalid choice");
		}
	default:
		break;
	}
	scanf_s("%d", &ch);
}