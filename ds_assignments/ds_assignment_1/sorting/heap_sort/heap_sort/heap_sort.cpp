#include<iostream>
using namespace std;
void swap(int *n1, int *n2)
{
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
void build_heap(int arr[],int i,int n)
{
	int temp = arr[i];
	int c;
	for (; (2 * i + 1) < n; i = c)
	{
		c = 2 * i + 1;
		if ((c + 1) < n&&arr[c + 1] > arr[c])
			c++;
		if (arr[c] > temp)
			arr[i] = arr[c];
	}
	arr[i] = temp;
}
void heapsort(int arr[],  int size)
{
	for (int i = ((size / 2) - 1); i >= 0; i++)
		build_heap(arr,i, size);
	for (int j = 1; j <= (size - 1); j++)
	{
		swap(&arr[0], &arr[size - j]);
		build_heap(arr, 0, size - j);
	}
}
int main()
{
	int size,*arr;
	cout << "enter the size of the array" << endl;
	cin >> size;
	arr = new int[size];
	cout << "enter the elements of the array" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	heapsort(arr, size);
	cout << "the elements after sorting are :" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i]<<endl;
	}
	system("pause");
	return 0;
}