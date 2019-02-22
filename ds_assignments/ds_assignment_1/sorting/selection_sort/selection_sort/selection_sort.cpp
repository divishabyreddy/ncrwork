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
	int num, *arr, loc,j;
	cout << "enter the size of the array" << endl;
	cin >> num;
	arr = new int[num];
	cout << "enter the elements of the array" << endl;
	for (int i = 0; i<num; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i<num - 1; i++)
	{
		loc = i;
		j = i + 1;
		while (j <= num - 1)
		{
			if (arr[j]<arr[loc])
				loc = j;
			j++;
		}
		swap(&arr[i], &arr[loc]);
	}
	cout << "the elements after sorting are" << endl;
	for (int i = 0; i<num; i++)
		cout << arr[i]<<endl;
	system("pause");
	return 0;
}
