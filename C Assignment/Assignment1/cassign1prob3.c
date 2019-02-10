#include<stdio.h>
int main()
{
	unsigned char hex = 0xCAFE, x,z;
	int y = 0;
	for (int i = 0; i < 4; i++)
	{
		x = (0xCAFE >> i)&(0x0001);
		if (x == 1)
			y++;
	}
	if (y >= 3)
		printf_s("Atleàst three of the last four bits are on");
	else
		printf_s("Atleàst three of the last four bits are not on");
	x = (0xCAFE << 8)|(0xCAFE >> 8);
	printf_s("%X\n", x);
	z = (0xCAFE << 12) | (0xCAFE >> 4);
	printf("%X\n", x);
	scanf_s("%d", &y);
	return 0;
}