#include<stdio.h>
#include<string.h>
void lwrtoupr(char c[]);
void uprtolwr(char c[]);
int main()
{
	char c[20];
	int x;
	printf_s("enter the string");
	scanf_s("%s", c);
	printf_s("choose an option \n 1.upper to lower \n 2. lower to upper");
	scanf_s("%d", &x);
	switch (x)
	{
	case 1:
		uprtolwr(c);
	case 2:
		lwrtoupr(c);
	}
  
	return 0;
}
void uprtolwr(char c[])
{
	int l = strlen(c);
	for (int i = 0; i < l; i++)
	{
		if ((c[i] >= 65) && (c[i] <= 90))
			c[i] = c[i] + 32;
	}
	printf_s("%s", c);
	scanf_s("%d", &l);
}
void lwrtoupr(char c[])
{
	int l = strlen(c);
	for (int i = 0; i < l; i++)
	{
		if ((c[i] >= 91) && (c[i] <= 116))
			c[i] = c[i] - 32;
	}
	printf_s("%s", c);
	scanf_s("%d", &l);
}

