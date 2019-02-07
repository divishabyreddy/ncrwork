#include<stdio.h>
#include<math.h>
int main()
{
int ch,n,num;
printf("choose the options \n 1.convert binary to decimal \n 2. convert decimal to binary \n");
scanf("%d",ch);
switch(ch)
{
case 1:
printf("enter the binary number which contains only 0's and 1's");
scanf("%d",&n);
num=btod(n);
printf("%d",num);
break;
case 2:
printf("enter the decimal number");
scanf("%d",&n);
num=dtob(n);
printf("%d",num);
break;
default:
printf("enter the valid option");
}
scanf("%d",&num);
}
int btod(int x)
{
int rev=x,n=0,sum=0,rem=x;
while(rev!=0)
{
rem=rem%10;
sum=sum+rem*pow(2,n);
n++;
rev=rev/10;
}
return sum;
}
int dtob(int x)
{
int rev=x,sum=0,rem=x;
while(rev!=0)
{
rem=rem%2;
sum=sum*10+rem;
rev=rev/2;
}
return sum;

}