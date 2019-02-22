#include<iostream>
using namespace std;
int main()
{
	int num, *arr, temp,j;
	cout << "enter the size of the array" << endl;
	cin >> num;
	arr = new int[num];
	cout << "enter the elements of the array" << endl;
	for (int i = 0; i<num; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i<num; i++)
	{
		j = i - 1;
		temp = arr[i];
		while (j >= 0 && arr[j]>temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
	cout << "the elements after sorting are" << endl;
	for (int i = 0; i<num; i++)
		cout << arr[i]<<endl;
	system("pause");
	return 0;
}
