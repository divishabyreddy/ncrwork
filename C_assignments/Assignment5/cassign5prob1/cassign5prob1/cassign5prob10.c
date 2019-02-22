#include<stdio.h>
struct time
{
	int hour;
	int min;
	int sec;
}t1;
int main()
{
	printf_s("enter the time in format hr min sec ");
	scanf_s("%d %d %d", &t1.hour, &t1.min, &t1.sec);
	while (t1.sec >= 60)
	{
		t1.min++;
		t1.sec -= 60;
	}
	while (t1.min >= 60)
	{
		t1.hour++;
		t1.min -= 60;
	}
	printf_s("the time is %d : %d : %d", t1.hour, t1.min, t1.sec);

	system("pause");
	return 0;
}