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
void Loang(int a[10][10], int n, int m, int i, int j)
{
	a[i][j] = 0;
	for (int k = 0; k < 4; k++)
	{
		if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < m && a[i + dx[k]][j + dy[k]] == 1)
		{
			Loang(a, n, m, i + dx[k], j + dy[k]);
		}
	}
}
int main()
{
	int a[10][10], n, m;
	InputArray(a, n, m);
	Loang(a, n, m, 0, 0);
	if (a[2][4] == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}