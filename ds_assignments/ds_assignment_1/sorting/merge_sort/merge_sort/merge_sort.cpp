#include<iostream>
using namespace std;
void merge(int arr[], int l1s, int l1e, int l2e)
{
	int l2s = l1e + 1;
	int *l3, i, j, k;
	l3 = new int[l2e - l1s + 1];
	i = l1s;
	j = l2s;
	k = 0;
	while (i <= l1e && j <= l2e)
	{
		if (arr[i]>arr[j])
			l3[k++] = arr[j++];
		else
			l3[k++] = arr[i++];
	}
	while (i <= l1e)
		l3[k++] = arr[i++];
	while (j <= l2e)
		l3[k++] = arr[j++];
	while (l2e >= l1s)
		arr[l2e--] = l3[--k];
	delete l3;
}
void mergesort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid;
		mid = (low + high) / 2;
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
	int main()
	{
		int num, *arr, loc;
		cout << "enter the size of the array" << endl;
		cin >> num;
		arr = new int[num];
		cout << "enter the elements of the array" << endl;
		for (int i = 0; i<num; i++)
		{
			cin >> arr[i];
		}
		mergesort(arr, 0, num - 1);
		cout << "the elements after sorting are" << endl;
		for (int i = 0; i<num; i++)
			cout << arr[i]<<endl;
		system("pause");
		return 0;
	}
