#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[100], b[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	int j = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i] - b[j]) <= 1)
		{
			cnt++;
			j++;
		}
		else if (abs(a[i] - b[j]) > 1)
		{
			if (a[i] > b[j])
			{
				i--;
				j++;
			}
		}
	}
	cout << cnt;
}
