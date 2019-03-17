/*creating a thread in suspended state*/
#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
DWORD WINAPI thread_func(LPVOID threadPar)
{
	int i;
	for (i = 1; i <= 1000; i++)
		printf("the value of i is %d\n", i);
	return 0;
}
int main()
{
	DWORD dwTh1;
	HANDLE hThread1;
	HANDLE hDummy;
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, CREATE_SUSPENDED, &dwTh1);
	Sleep(5000);
	ResumeThread(hThread1);
	hDummy = hThread1;
	WaitForMultipleObjects(1, &hDummy, TRUE, INFINITE);
	CloseHandle(hThread1);
	getchar();
	return 0;
}