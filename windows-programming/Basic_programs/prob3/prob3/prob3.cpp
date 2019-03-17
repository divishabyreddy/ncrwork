/*Write a program to print environment variables passed to the console application. Also demonstrate the usage of ExpandEnvironmentStrings API. 
*/
#include<stdio.h>
#include<Windows.h>
#include<shellapi.h>
#include<string.h>
#include<tchar.h>
void DumpEnvStrings(PTSTR PEnvBlock[])
{
	int current = 0;
	PTSTR * PElement = (PTSTR *)PEnvBlock;
	PTSTR pCurrent = NULL;
	while (PElement != NULL)
	{
		pCurrent = (PTSTR)(*PElement);
		if (pCurrent == NULL)
		{
			PElement = NULL;
		}
		else
		{
			_tprintf(TEXT("[%u]  %S \r \n"), current, pCurrent);
			current++;
			PElement++;
		}
	}

}
int main(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvStrings(env);
	TCHAR envString1[] = TEXT("%windir%");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envString1, buffer, MAX_PATH);
	if (!ret)
	{
		printf_s("%d \n", GetLastError());
		return 0;
	}
	else
	{
		printf_s("%s \n", buffer);
	}
	system("pause");
	return 0;
}