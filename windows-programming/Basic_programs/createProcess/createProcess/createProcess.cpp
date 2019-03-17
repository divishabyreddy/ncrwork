/*creating a prpcess*/
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO s;
	PROCESS_INFORMATION p;
	ZeroMemory(&s, sizeof(s));
	s.cb = sizeof(s);
	ZeroMemory(&p, sizeof(p));
	if (argc != 2)
	{
		printf("arguments are not enough\n");
		printf("the error is %d\n", GetLastError());
		getchar();
		return FALSE;
	}
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &s, &p))
	{
		printf("error in creation of process\n");
		printf("the error is %d\n", GetLastError());
		getchar();
		return FALSE;
   }
	printf("handle of the process is %d\n", p.hProcess);
	printf("process ID of the process is %d", p.dwProcessId);
	DWORD dwRet = WaitForSingleObject(p.hProcess, INFINITE);
	printf("wait for single object output %d\n", dwRet);
	printf("the value of current process id is %d\n", GetCurrentProcessId());
	printf("the current thread id is %d\n", GetCurrentThreadId());
	printf("the process id is %d\n", GetProcessId(p.hProcess));
	printf("the thread id is %d\n",GetThreadId(p.hThread));
	printf("the process id of thread is %d\n", GetProcessIdOfThread(p.hThread));
	getchar();
	return FALSE;
}