#include<iostream>
using namespace std;
int main()
{
	int size,*arr,ele,i,flag=0;
	cout << "enter the size of the array" << endl;
	cin >> size;
	arr = new int[size];
	cout << "enter the elements of the array" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << "enter the element to be searched" << endl;
	cin >> ele;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == ele)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
		cout << "element is found at location : " << i + 1 << endl;
	else
		cout << "element is not present in the array" << endl;
	system("pause");
	return 0;
}