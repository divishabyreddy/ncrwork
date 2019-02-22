#include<iostream>
using namespace std;
void swap(int *n1, int *n2)
{
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
int main()
{
	int num, *arr, flag;
	cout << "enter the size of the array" << endl;
	cin >> num;
	arr = new int[num];
	cout << "enter the elements of the array" << endl;
	for (int i = 0; i<num; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < num; i++)
	{
		flag = 0;
		for (int j = 0; j < num - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (flag==0)
			break;
	}
		cout << "the elements after sorting are" << endl;
		for (int i = 0; i<num; i++)
			cout << arr[i]<<endl;
		delete arr;
		system("pause");
		return 0;
	}
