#include<stdio.h>
#include<stdlib.h>
int balancingParanthesis(char *);
int validate(char *str)
{
	if (balancingParanthesis(str) == 1)//checks whether the symbols are balanced
	{
		//if  paranthesis are balanced there then function returns '1'
		return 1;
	}
	else
	{
		//if  paranthesis are not balanced there then function returns '0'
		printf_s("\n in the expression balanced paranthesis are not there");
		printf_s("\n the expression is invalid");
		return 0;
	}

}
