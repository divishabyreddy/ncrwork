#include<stdio.h>
int main()
{
int n;
int rev,rem,sum=0;
printf_s("enter the number");
scanf_s("%d",&n);
rem=n;
rev=n;
while(rev!=0)
{
rem=rev%10;
sum=sum*10+rem;
rev=rev/10;
}
printf("reverse of the number is %d",sum);
}
