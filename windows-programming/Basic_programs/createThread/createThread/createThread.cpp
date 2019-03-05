#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<stdlib.h>
DWORD WINAPI thread_func(LPVOID lpPar)
{
	for (int i = 0; i < 10; i++)
	{
		printf("i=%d\n", i);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD th1, th2;
	HANDLE hTh1, hTh2;
	HANDLE hArr[2];
	hTh1 = CreateThread(NULL, 0, thread_func, NULL, 0, &th1);
	hTh2 = CreateThread(NULL, 0, thread_func, NULL, 0, &th2);
	if (hTh1 == NULL)
	{
		printf("error in creating the thread");
		getchar();
		return FALSE;
	}
	if (hTh2 == NULL)
	{
		printf("error in creating the thread");
		getchar();
		return FALSE;
	}
	hArr[0] = hTh1;
	hArr[1] = hTh2;
	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);
	CloseHandle(hTh1);
	CloseHandle(hTh2);
}