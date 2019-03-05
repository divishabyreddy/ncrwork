/*creating a thread*/
#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#define Buff_size 255

void DisplayMessage(HANDLE hScreen,
	char *ThreadName, int Data, int Count)
{
	TCHAR msgbuf[Buff_size];
	size_t cchStringSize;
	DWORD dwChars;
	StringCchPrintf(msgbuf, Buff_size, TEXT("EXECUTING ITERATION %d of %s having data %d"),
		Count, ThreadName, Data);
	StringCchLength(msgbuf, Buff_size, &cchStringSize);
	WriteConsole(hScreen, msgbuf, cchStringSize, &dwChars, NULL);
	Sleep(1000);

}