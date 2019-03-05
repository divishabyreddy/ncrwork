/*creating child processes*/
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO s1, s2;
	PROCESS_INFORMATION p1, p2;
	ZeroMemory(&s1, sizeof(s1));
	s1.cb = sizeof(s1);
	ZeroMemory(&p1, sizeof(p1));
	ZeroMemory(&s2, sizeof(s2));
	s2.cb = sizeof(s2);
	ZeroMemory(&p2, sizeof(p2));
	if (argc != 3)
	{
		printf("arguments are not enough\n");
		printf("the error code is %d\n", GetLastError());
		getchar();
		return FALSE;
	}
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &s1, &p1))
	{
		printf("error in creating the process\n");
		printf("the error id is %d\n", GetLastError());
		getchar();
		return FALSE;
	}
	printf("the handle of the process is %d\n", p1.hProcess);
	printf("process id of the process is %d\n", p1.dwProcessId);
	DWORD dwRet = WaitForSingleObject(p1.hProcess, INFINITE);
	printf("wait for single object output %d \n", dwRet);
	if (!CreateProcess(NULL, argv[2], NULL, NULL, FALSE, 0, NULL, NULL, &s2, &p2))
	{
		printf("error in creating the process\n");
		printf("the error id is %d\n", GetLastError());
		getchar();
		return FALSE;
	}
	printf("the handle of the process is %d\n", p2.hProcess);
	printf("process id of the process is %d\n", p2.dwProcessId);
	dwRet = WaitForSingleObject(p2.hProcess, INFINITE);
	printf("wait for single object output %d \n", dwRet);
	getchar();
	return TRUE;
}