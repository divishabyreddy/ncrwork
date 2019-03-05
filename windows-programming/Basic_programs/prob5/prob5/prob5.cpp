#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	TCHAR buffer[] = TEXT("hi this is shivani");
	if (argc != 2)
	{
		_tprintf(_T("less number of arguments to main function \n sample argumnets: filename.exe filename"));
		getchar();
		return FALSE;
	}
	hFile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		_tprintf(_T("cannot open the file error number:%d"), GetLastError());
		_tprintf(_T("for more info refer ERROR LOOKUP"));
		getchar();
		return FALSE;
	}
	_tprintf(_T("file opened (%s) successfully"), argv[1]);
	DWORD dwNbr;
	//ZeroMemory(buffer, bufferSize);
	BOOL ret = WriteFile(hFile, buffer, sizeof(buffer), &dwNbr, NULL);
	if (0 == ret)
	{
		_tprintf(_T("cannot read the file error number:%d"), GetLastError());
		_tprintf(_T("for more info refer ERROR LOOKUP"));
		getchar();
		return FALSE;
	}
	CloseHandle(hFile);
	_tprintf(_T("text from the file [%s] is ....: \n %S"), argv[1], buffer);

	getchar();
	return TRUE;
}