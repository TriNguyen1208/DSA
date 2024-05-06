#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;

void InputArray(int a[10][10], int& n, int& m)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
}
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
void Loang(int a[10][10], int n, int m, int i, int j, int& count)
{
	a[i][j] = 0;
	for (int k = 0; k < 4; k++)
	{
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == 1)
		{
			count++;
			Loang(a, n, m, i1, j1, count);
		}
	}
}
int main()
{
	int a[10][10], n, m;
	InputArray(a, n, m);
	int Max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
			{
				int count = 1;
				Loang(a, n, m, i, j, count);
				Max = max(Max, count);
			}
		}
	}
	cout << Max;
}

