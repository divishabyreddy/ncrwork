#include<stdio.h>
int main()
{
	int n, temp;
	printf_s("enter the no of elements of the array");
	scanf_s("%d", &n);
	int arr[10];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf_s("%d", arr[i]);
	scanf_s("%d", &n);
}