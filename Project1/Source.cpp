#include<iostream>
#include<algorithm>
using namespace std;

bool IsTriangle(int x, int y, int z)
{
	if (x + y > z && x + z > y && y + z > x)
	{
		return true;
	}
	return false;
}
void greedyAlgorithm(int a[], int n)
{
	for (int i = n - 1; i >= 2; i--)
	{
		if (IsTriangle(a[i - 2], a[i - 1], a[i]))
		{
			cout << a[i - 2] << " " << a[i - 1] << " " << a[i];
			return;
		}
	}
	cout << -1;
}
int luu[3];
void backtrackAlgorithm(int a[], int save[], int n, int& Max, int cnt = 0, int start = 0)
{
	if (cnt == 3)
	{
		if (IsTriangle(save[0], save[1], save[2]))
		{
			Max = max(Max, save[0] + save[1] + save[2]);
			if (save[0] + save[1] + save[2] == Max)
			{
				for (int i = 0; i < 3; i++)
				{
					luu[i] = save[i];
				}
			}
		}
		return;
	}
	for (int i = start; i < n; i++)
	{
		save[cnt] = a[i];
		backtrackAlgorithm(a, save, n, Max, cnt + 1, i + 1);
	}
}
int main()
{
	int a[100], n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int save[100];
	int Max = INT_MIN;
	backtrackAlgorithm(a, save, n, Max);
	for (int i = 0; i < n; i++)
	{
		cout << luu[i] << " ";
	}
}