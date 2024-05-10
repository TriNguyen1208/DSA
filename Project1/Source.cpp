#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
using namespace std;

bool check(int a[], int n, int k, double maxWire)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res = res + (int)a[i] / maxWire;
	}
	return res >= k;
}
int main()
{
	int n, k; cin >> n >> k;
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	double left = 0, right = *max_element(a, a + n) * k;
	double res = 0;
	for(int i = 0;i < 60;i++)
	{
		double mid = (left + right) / 2;
		if (check(a, n, k, mid) == true)
		{
			res = mid;
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	cout << setprecision(6) << fixed << res;
	return 0;
}