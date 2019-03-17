/*secondary thread*/
#include<stdio.h>
#include<tchar.h>
#include<Windows.h>
DWORD WINAPI thread_func2(LPVOID lpPar)
{
	printf("control entered into the second thread");
	getchar();
	ExitThread(20);
	return 0;
}
DWORD WINAPI thread_func1(LPVOID lpPar)
{
	printf("control entered into the first thread");
	getchar();
	DWORD dwTh2;
	HANDLE hTh2;
	DWORD exitcode;
	hTh2 = CreateThread(NULL, 0, thread_func2, NULL, CREATE_SUSPENDED, &dwTh2);
	ResumeThread(hTh2);
	WaitForSingleObject(hTh2, INFINITE);
	GetExitCodeThread(hTh2, &exitcode);
	printf("the exit code of the second thread is %d\n", exitcode);
	return 0;
}
int main()
{
	DWORD dwTh1;
	HANDLE hTh1;
	hTh1 = CreateThread(NULL, 0, thread_func1, NULL, CREATE_SUSPENDED, &dwTh1);
	ResumeThread(hTh1);
	WaitForSingleObject(hTh1, INFINITE);
	getchar();
	return 0;
}