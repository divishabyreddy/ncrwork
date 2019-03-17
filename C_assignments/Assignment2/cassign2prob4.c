#include<stdio.h>
int main()
{
int flag=0,a,b,i;
print_f("enter the range of numbers");
scan_f("%d%d",&a,&b);
for(i=a+1;i<b;i++)
{
for(int j=2;j<=i/2;j++)
{
if(i%j==0)
flag=1;
}
if(flag==0)
printf_s("%d",i);
}
}