#include<stdio.h>
int main()
{
	int n, min, max,  j = 0;
	float avg = 0;
	printf_s("enter the numbers");
	scanf_s("%d", &n);
	min = n;
	max = n;
	while (n > 0)
	{
		j++;
		
		if (n > max)
			max = n;
		else if(n < min)
			min = n;
		avg = avg + n;
		scanf_s("%d", &n);

	}
	printf_s("the minimum value is %d\n", min);
	printf_s("the maximum value is %d\n", max);
	printf_s("the average of numbers is %f\n", avg / j);
	scanf_s("%d", &n);
	return 0;
}