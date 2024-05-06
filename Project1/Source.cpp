#include<iostream>
using namespace std;

void InputArray(int a[10][10], int& N, int& s, int& t)
{
	cin >> N >> s >> t;
	s--, t--;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}
}
int dx[4] = { -1, -1, 1, 1 };
int dy[4] = { -1, 1, -1, 1 };
void Loang(int a[10][10], int N, int s, int t, int count)
{
	a[s][t] = 1;
	for (int k = 0; k < 4; k++)
	{
		int i = s + dx[k], j = t + dy[k];
		if (i >= 0 && i < N && j >= 0 && j < N && a[i][j] == 0)
		{
			count++;
			Loang(a, N, i, j, count);
		}
	}
}
int main()
{
	int a[10][10], N, s, t;
	InputArray(a, N, s, t);
	int count = 1;
	Loang(a, N, s, t, count);
	cout << count;
}
