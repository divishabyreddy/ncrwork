/*creating a process and passing handle to child process*/
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO s1, s2;
	PROCESS_INFORMATION p1,p2;
	SECURITY_ATTRIBUTES sa;
	HANDLE hp1, hp2;
	if (argc != 2)
	{
		_tprintf(TEXT("wrong number of arguments passed\n"));
		_tprintf(TEXT("the error code is %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	ZeroMemory(&s1, sizeof(s1));
	s1.cb = sizeof(s1);
	ZeroMemory(&p1, sizeof(p1));
	ZeroMemory(&s2, sizeof(s2));
	s2.cb = sizeof(s2);
	ZeroMemory(&p2, sizeof(p2));
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if (!CreateProcess(NULL, argv[1], &sa, NULL, TRUE, 0, NULL, NULL, &s1, &p1))
	{
		_tprintf(TEXT("process creation error"));
		_tprintf(TEXT("\n for more information refer error number %d"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(TEXT("the process id is %d \n"), p1.dwProcessId);
	getchar();
	return TRUE;
}