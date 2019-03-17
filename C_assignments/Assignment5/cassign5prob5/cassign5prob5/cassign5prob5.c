#include<stdio.h>
#include<stdlib.h>
int main()
{
	int day1, day2, month1, month2, year1, year2,leapyr=0,sum1=0,sum2=0,diff=0;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf_s("enter the two dates in dd mm yy format");
	scanf_s("%d %d %d %d %d %d", &day1, &day2, &month1, &month2, &year1, &year2);
	leapyr = abs((year1 / 4 - year1 / 100+year1/400)-(year2/ 4 - year2 / 100 +year1/400));
	printf_s("%d", leapyr);
	sum1 = (year1 - 1) * 365;
	for (int i = 1; i < month1; i++)
	{
		sum1 = sum1 + month[i - 1];
	}
	sum1 = sum1 + day1;
	sum2 = (year2 - 1) * 365;
	for (int i = 1; i < month2; i++)
	{
		sum2 = sum2 + month[i - 1];
	}
	sum2 = sum2 + day2;
	diff = abs(sum2 - sum1);
	diff = diff + leapyr;
	printf_s("the difference between the dates in days is %d", diff);
	scanf_s("%d", &day1);
	return 0;
}