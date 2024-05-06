#include<iostream>
using namespace std;

void InputArray(int a[10][10], int& N)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}
}
int dy[3] = { -1, 0, 1 };
void MaximumPath(int a[10][10], int tmp[10][10], int N)
{
	for (int i = 0; i < N; i++)
	{
		tmp[0][i] = a[0][i];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int Max = INT_MIN;
			for (int k = 0; k < 3; k++)
			{
				if (j + dy[k] >= 0 && j + dy[k] < N)
				{
					Max = max(Max, a[i - 1][j + dy[k]]);
				}
			}
			tmp[i][j] = a[i][j] + Max;
		}
	}
}
int main()
{
	int a[10][10], tmp[10][10], N;
	InputArray(a, N);
	MaximumPath(a, tmp, N);
	int Max = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		Max = max(Max, tmp[N - 1][i]);
	}
	cout << Max;
}