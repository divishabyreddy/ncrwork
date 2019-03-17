/*Write a program to convert ANSI string to Wide character string and vice versa.
Use MultiByteToWideChar and WideCharToMultiByte for conversion and IsTextUnicode for testing the results.*/
#include<stdio.h>
#include<Windows.h>
#include<string.h>
void main()
{
	CHAR c = 'D';
	WCHAR wc = L'D';
	CHAR ansi[] = "ANSI";
	WCHAR wchar[] = L"wchar";
	printf_s("the value of char is %c\n", c);
	printf_s("the value of wchar is %C\n", wc);
	printf_s("the value of char is %s\n", ansi);
	printf_s("the value of wchar is %S\n", wchar);
	printf_s("the length of the wchar is %d\n", wcslen(wchar));
	int ret = IsTextUnicode(ansi, sizeof(ansi), NULL);
	if (0 == ret)
		printf_s("the string is not in unicode format\n");
	else if (1 == ret)
		printf_s("the string is in unicode format\n");
	else
	{
		printf_s("error has been occured\n");
		GetLastError();
		system("pause");
		return;
	}
	ret = IsTextUnicode(wchar, sizeof(wchar), NULL);
	if (0 == ret)
		printf_s("the string is not in unicode format\n");
	else if (1 == ret)
		printf_s("the string is in unicode format\n");
	else
	{
		printf_s("error has been occured\n");
		GetLastError();
		system("pause");
		return;
	}
	//conversion from multibyte to wchar
	int res = MultiByteToWideChar(CP_UTF8, 0, ansi, -1, NULL, 0);
	if (0 == res)
	{
		printf_s("some error occured\n");
		GetLastError();
		system("pause");
		return;
	}
	printf_s("the size required for the buffer is %d\n", res);
	WCHAR* op;
	op = new WCHAR[res];
	ret = MultiByteToWideChar(CP_UTF8, 0, ansi, strlen(ansi), op, wcslen(op));
	if (0 == ret)
	{
		printf_s("some error occured\n");
		GetLastError();
		system("pause");
		return;
	}
	printf_s("ansi to wchar conversion has taken place\n");
	//printf_s("the string is %ls\n", op);
	printf_s("the string is %S\n", op);
	free(op);
	//conversion from wchar to multibyte
	int x = WideCharToMultiByte(CP_UTF8, 0, wchar, -1, NULL, 0, NULL, NULL);
	if (0 == x)
	{
		printf_s("some error occured\n");
		GetLastError();
		system("pause");
		return;
	}
	printf_s("the size of the buffer required is %d\n", x);
	CHAR* ans = new CHAR[x];
	x = WideCharToMultiByte(CP_UTF8, 0, wchar, wcslen(wchar), ans, strlen(ans), NULL, NULL);
	if (0 == x)
	{
		printf_s("some error has occured\n");
		GetLastError();
		system("pause");
		return;
	}
	printf_s("the string is converted from wchar to multibyte\n");
	printf_s("the string is %s\n", ans);
	GetLastError();
	free(ans);
	scanf_s("%d", &x);
	system("pause");
}
