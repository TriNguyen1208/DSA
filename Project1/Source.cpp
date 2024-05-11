#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

void backtrack(int a[], int n, int start = 0)
{
	if (start == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i];
		}
		cout << endl;
		return;
	}
	for (int i = 0; i <= 1; i++)
	{
		a[start] = i;
		backtrack(a, n, start + 1);
		a[start] = 0;
	}
}
void sinh(int a[], int n, int& final)
{
	int i = n - 1;
	while (i >= 0 && a[i] == 1)
	{
		a[i] = 0;
		i--;
	}
	if (i == -1)
	{
		final = 1;
	}
	else
	{
		a[i] = 1;
	}
}
int main()
{
	int a[100] = { 0 };
	string name[100] = { "Tom", "Jerry", "Jack" };
	int final = 0;
	int n;
	cin >> n;
	while (final == 0)
	{
		for (int i = 0;i < n; i++)
		{
			if (a[i] == 1)
			{
				cout << name[i] << " ";
			}
		}
		cout << endl;
		sinh(a, n, final);
	}
}