#include<iostream>
using namespace std;

bool IsDescending(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i + 1] > a[i])
		{
			return false;
		}
	}
	return true;
}
void backtrack(int a[], int n, int sum = 0, int cnt = 0)
{
	if (sum == n)
	{
		if (IsDescending(a, cnt) == true)
		{
			for (int i = 0; i < cnt; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = 5; i > 0; i--)
	{
		if (sum + i <= n)
		{
			a[cnt] = i;
			backtrack(a, n, sum + i, cnt + 1);
			a[cnt] = 0;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int a[100];
	backtrack(a, n);
}