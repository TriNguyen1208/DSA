#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

bool check(int a[], int n, int t, int time)
{
	int time_res = 0;
	for (int i = 0; i < n; i++)
	{
		time_res = time_res + (time / a[i]);
	}
	return time_res >= t;
}
int main()
{
	int n, t; cin >> n >> t;
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	long long left = 0, right = *min_element(a, a + n) * t;
	long long res = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (check(a, n, t, mid) == true)
		{
			res = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << res;
}
