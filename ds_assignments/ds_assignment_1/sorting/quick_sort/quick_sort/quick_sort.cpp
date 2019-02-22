#include<iostream>
using namespace std;
void swap(int *n1, int *n2)
{
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
void quicksort(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i, j;
	i = low + 1;
	j = high;
	if (low<high)
	{
		while (1)
		{
			while (i <= high&&arr[i]<pivot)
				i++;
			while (arr[j]>pivot)
				j--;
			if (i<j)
				swap(&arr[i], &arr[j]);
			else
				break;
		}
		swap(&arr[low], &arr[i]);
		quicksort(arr,low, j - 1);
		quicksort(arr,j + 1, high);
	}
}
int main()
{
	int num, *arr, loc;
	cout << "enter the size of the array" << endl;
	cin >> num;
	arr = new int[num];
	cout << "enter the elements of the array" << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	quicksort(arr, 0, num - 1);
	cout << "the elements after sorting are" << endl;
	for (int i = 0; i < num; i++)
		cout << arr[i] << endl;
	system("pause");
	return 0;
}


