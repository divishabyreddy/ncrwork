#include<stdio.h>
#include<math.h>
int main()
{
    	float p,q,r,SI,CI;
    	int n;
   	printf("Enter the value of Principal p = ");
    	scanf("%f",&p);
    	printf("Enter the value of Rate r = ");
    	scanf("%f",&r);
    	printf("Enter the value of Period in year n = ");
    	scanf("%d",&n);
   	SI = ((p*r*n)/100);
	printf("Simple Interest SI=%f \n",SI);
	q = 1+(r/100);
	CI=p*pow(q,n)-p;
   	printf("Compound Interest CI=%f \n",CI);
	return 0; 	  
}