/*shared integer*/
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
long sharedInt = 1;
DWORD WINAPI thread_func1(LPVOID lpPar)
{
	sharedInt++;
	printf("control entered into the first thread\n");
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lpPar)
{
	sharedInt++;
	printf("control entered into the second thread\n");
	return 0;
}
int main()
{
	DWORD dw1,dw2;
	HANDLE hTh1, hTh2;
	HANDLE harr[2];
	hTh1 = CreateThread(NULL, 0, thread_func1, NULL, 0, &dw1);
	hTh2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &dw2);
	if (hTh1 == NULL)
	{
		printf("error in  creating the thread1\n");
		printf("the error code is %d\n", GetLastError());
		getchar();
		return 0;
	}
	if (hTh2 == NULL)
	{
		printf("error in creating thr thread2 \n");
		printf("the error code is %d\n", GetLastError());
		return 0;
	}
	harr[0] = hTh1;
	harr[1] = hTh2;
	WaitForMultipleObjects(2, harr, TRUE, INFINITE);
	CloseHandle(hTh1);
	CloseHandle(hTh2);
	printf("the value of the variable sharedInt is %d\n", sharedInt);
	getchar();
	return 0;
}