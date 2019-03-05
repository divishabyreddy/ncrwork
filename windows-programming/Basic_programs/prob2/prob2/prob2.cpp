#include<Windows.h>
#include<stdio.h>
#include<shellapi.h>
int main()
{
	LPWSTR *argList;
	int nArgs;
	int i;
	argList = CommandLineToArgvW(GetCommandLine(), &nArgs);
	if (NULL == argList)
	{
		wprintf(L"CommandLineToArgvW failed\n");
		return 0;
	}
	else
	{
		for (i = 0; i < nArgs; i++)
			printf("%d: %ws\n", i, argList[i]);
	}
	LocalFree(argList);
	system("pause");
	return 0;
}