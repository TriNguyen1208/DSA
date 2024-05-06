#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;

void InputArray(int a[10][10], int& n, int& s, int& t, int& u, int& v)
{
	cin >> n >> s >> t >> u >> v;
	s--, t--, u--, v--;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
}
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
void Loang(int a[10][10], int n, int s, int t)
{
	a[s][t] = 0;
	for (int k = 0; k < 8; k++)
	{
		int i = s + dx[k], j = t + dy[k];
		if (i >= 0 && i < n && j >= 0 && j < n && a[i][j] == 1)
		{
			Loang(a, n, i, j);
		}
	}
}
int main()
{
	int a[10][10], n, s, t, u, v;
	InputArray(a, n, s, t, u, v);
	Loang(a, n, s, t);
	if (a[u][v] == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
