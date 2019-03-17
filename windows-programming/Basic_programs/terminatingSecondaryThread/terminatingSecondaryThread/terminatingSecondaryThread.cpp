/*terminating secondary thread*/
#include<Windows.h>
#include<tchar.h>
#include<stdio.h>
DWORD WINAPI thread_func2(LPVOID lpPar)
{
	printf("the control is entered into second thread\n");
	Sleep(8000);
	return 0;
}
DWORD WINAPI thread_func1(LPVOID lpPar)
{
	printf("the control is entered into the first thread\n");
	DWORD dwTh2;
	HANDLE hTh2;
	DWORD exitcode;
	hTh2 = CreateThread(NULL, 0, thread_func2, NULL, CREATE_SUSPENDED, &dwTh2);
	ResumeThread(hTh2);
	Sleep(2000);
	TerminateThread(hTh2, 2);
	Sleep(2000);
	GetExitCodeThread(hTh2, &exitcode);
	printf("the exitcode of thread2 is %d\n", exitcode);
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