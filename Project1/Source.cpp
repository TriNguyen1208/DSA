#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int sum(int a[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res = res + a[i];
	}
	return res;
}
int compare(int a[], int n, int k, int maxSum)
{
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + a[i] > maxSum)
		{
			cnt++;
			sum = 0;
		}
		sum = sum + a[i];
	}
	cnt++;
	if (cnt > k) //lower
	{
		return 1;
	}
	else//greater
	{
		return 0;
	}
}
int main()
{ 
	int n, k; cin >> n >> k;
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int left = 0, right = sum(a, n);
	int res = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int maxSum = 0;
		if (compare(a, n, k, mid) == 0)
		{
			right = mid - 1;
			res = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << res;
}