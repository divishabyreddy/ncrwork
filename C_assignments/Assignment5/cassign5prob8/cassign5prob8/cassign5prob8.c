#include<stdio.h>
#define	NUM 0
#define ONE 1
#define PRINTS printf_s("%d",y1)
#define PRINT(s) printf_s("y"#s"=%d\n",y##s)
int main()
   {
	int x=5, y1=7;
	
	PRINT(1);
#if  NUM
	printf_s("%d", x);
#elif ONE
	PRINTS;
#endif
	scanf_s("%d",&x);
	return 0;
   }