/*Write a C++ program to define a matrix and do matrix-vector multiplication using a
friend function*/
#include<iostream>
using namespace std;
class Matrix
{
	
	int a[10][10];
	int m, n;
public:
	Matrix()
	{
		m = n = 0;
	}
	Matrix(int a, int b)
	{
		m = a;
		n = b;
	}
	void set_data()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
	}
	void get_data()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << a[i][j];
			}
		}
	}
	friend Matrix multiplication(Matrix m1, Matrix m2);
};
Matrix multiplication(Matrix m1, Matrix m2)
{
	Matrix temp();
	if (m1.n != m2.m)
	{
		cout << "matrix multiplication not possible" << endl;
		return;
	}
	else
	{
		
		for (int i = 0; i < m1.m; i++)
		{
			for (int j = 0; j < m2.n; j++)
			{
				for (int k = 0; k < m2.n; k++)
				{
					temp.a[i][j] = temp.a[i][j] + m1.a[i][k] * m2.a[k][j];
				}
			}
		}
		
	}
	return temp;
}
int main()
{
	Matrix m1(2, 2), m2(2, 1),m3;
	m1.set_data();
	m2.set_data();
	
	m3=multiplication(m1, m2);
	m3.get_data();
	return 0;
}