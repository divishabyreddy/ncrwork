#include<iostream>
#include<string.h>
using namespace std;
int balancingParanthesis(char*);
void infixToPostfix(char *);
int main()
{
	char s[20],val;
	int num,i=0;
	printf_s("enter the expression\n");
	gets_s(s);
	if (balancingParanthesis(s))
	{
		printf_s("symbols are balanced\n");
		//infixToPostfix(s);
	}
	/*else
	{
		printf_s("symbols are not balanced\n");
		exit(1);
	}*/
	system("pause");
	return 0;
}