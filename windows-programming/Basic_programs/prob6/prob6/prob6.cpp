/*Write a program to create a process using CreateProcess API. Child process can be any your previously implemented programs.
*/
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	//HANDLE hProcess;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (argc != 2)
	{
		printf("no of arguments are not enough");
		printf("\n the error number is: %d", GetLastError());
		getchar();
		return FALSE;
	}
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		printf("error in creation of process");
		printf("\n the error number is: %d", GetLastError());
		getchar();
		return FALSE;

	}
	printf_s("Handle of the process is %d \n ", pi.hProcess);
	printf_s("process ID of the process is %d \n ", pi.dwProcessId);
	DWORD dwRet = WaitForSingleObject(pi.hProcess, INFINITE);
	printf_s("wait for single object output %d \n", dwRet);
	getchar();
	return TRUE;
}