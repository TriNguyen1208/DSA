#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;


long long binPow(long long a, long long b, long long c)
{
	if (b == 0)
	{
		return 1;
	}
	long long res = binPow(a, b / 2, c);
	if (b % 2 == 0)
	{
		return ((res % c) * (res % c)) % c;
	}
	else if (b % 2 == 1)
	{
		return ((res % c) * (res % c) * a) % c;
	}
}
bool binarySearch(int a[], int N, int x)
{
	int left = 0, right = N - 1;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		if (a[mid] == x)
		{
			return true;
		}
		else if (a[mid] < x) // find out on the right of middle
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return false;
}
bool binarySearchRecursion(int a[], int left, int right, int x)
{
	if (left > right)
	{
		return false;
	}
	int mid = (left + right) / 2;
	if (a[mid] < x)
	{
		return binarySearchRecursion(a, mid + 1, right, x);
	}
	else if (a[mid] > x)
	{
		return binarySearchRecursion(a, left, mid - 1, x);
	}
	else
	{
		return true;
	}
}
int firstPos(int a[], int left, int right, int x, int res = -1)
{
	if (left > right)
	{
		return res;
	}
	int mid = (left + right) / 2;
	if (a[mid] < x)
	{
		return firstPos(a, mid + 1, right, x, res);
	}
	else if (a[mid] > x)
	{
		return firstPos(a, left, mid - 1, x, res);
	}
	else
	{
		return firstPos(a, left, mid - 1, x, mid);
	}
}
int lastPos(int a[], int left, int right, int x, int res = -1)
{
	if (left > right)
	{
		return res;
	}
	int mid = (left + right) / 2;
	if (a[mid] < x)
	{
		return lastPos(a, mid + 1, right, x, res);
	}
	else if (a[mid] > x)
	{
		return lastPos(a, left, mid - 1, x, res);
	}
	else
	{
		return lastPos(a, mid + 1, right, x, mid);
	}
}
int lower(int a[], int left, int right, int x, int res = -1)
{
	if (left > right)
	{
		return res;
	}
	int mid = (left + right) / 2;
	if (a[mid] < x)
	{
		return lower(a, mid + 1, right, x, res);
	}
	else if (a[mid] >= x)
	{
		return lower(a, left, mid - 1, x, mid);
	}
}
int main()
{
	int a[] = { 1, 1, 2, 2, 3, 3, 4, 4, 4, 6, 7 };
	int k = 5;
	int cnt = 0;
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++)
	{
		auto it1 = lower_bound(a + i + 1, a + n, k - a[i]);
		auto it2 = upper_bound(a + i + 1, a + n, k - a[i]);
		cnt = cnt + it2 - it1;
	}
	cout << cnt;
}
//5
//534 7 669 826 610