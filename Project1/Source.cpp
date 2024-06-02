#include<iostream>
using namespace std;

long long f[100];
void initFibo()
{
	f[1] = 1; f[2] = 1;
	for (int i = 3; i < 100; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
}
char fiboString(int n, long long k)
{
	if (n == 1)
	{
		return 'A';
	}
	if (n == 2)
	{
		return 'B';
	}
	if (k <= f[n - 2])
	{
		return fiboString(n - 2, k);
	}
	else if (k > f[n - 2])
	{
		return fiboString(n - 1, k - f[n - 2]);
	}
}
void countBinarySearch(int a[], int count[], int left, int right, int cnt = 1)
{
	if (left > right)
		return;
	int mid = (left + right) / 2;
	count[mid] = cnt;
	countBinarySearch(a, count, left, mid - 1, cnt + 1);
	countBinarySearch(a, count, mid + 1, right, cnt + 1);
}
int maximumSubArray1(int a[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum = sum + a[j];
			if (sum > max)
			{
				max = sum;
			}
		}
	}
	return max;	
}
void InputArray(int a[], int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
int Max(int a, int b, int c)
{
	return max(max(a, b), c);
}
int maxFromLeftToRightThroughMid(int a[], int l, int m, int r)
{
	int Sumleft = INT_MIN;
	int sum = 0;
	for (int i = m; i >= l; i--)
	{
		sum = sum + a[i];
		if (sum > Sumleft)
		{
			Sumleft = sum;
		}
	}
	sum = 0;
	int Sumright = 0;
	for (int i = m; i <= r; i++)
	{
		sum = sum + a[i];
		if (sum > Sumright)
		{
			Sumright = sum;
		}
	}
	return Max(Sumleft, Sumright, Sumleft + Sumright - a[m]);
}
int maxSubArraySum(int a[], int l, int r)
{
	if (l > r)
	{
		return INT_MIN;
	}
	if (l == r)
	{
		return a[l];
	}
	int mid = (l + r) / 2;
	int sLeft = maxSubArraySum(a, l, mid - 1);
	int sRight = maxSubArraySum(a, mid + 1, r);
	int sCrossing = maxFromLeftToRightThroughMid(a, l, mid, r);
	return Max(sLeft, sRight, sCrossing);
}
// 8 -2 -5 6 -2 -3 1 5 -6
int floor(int a[], int num, int l, int r)
{
	if (l >= r)
	{
		return INT_MAX;
	}
	int mid = (l + r) / 2;
	if (a[mid] < num)
	{
		return floor(a, num, mid + 1, r);
	}
	else if (a[mid] >= num)
	{
		int s = floor(a, num, l, mid - 1);
		return min(a[mid], s);
	}
}
int count0(int a[], int l, int r)
{
	if (l >= r)
	{
		return r + 1;
	}
	int mid = (l + r) / 2;
	if (a[mid] == 1)
	{
		return count0(a, l, mid - 1);
	}
	if (a[mid] == 0)
	{
		return count0(a, mid + 1, r);
	}
}
void countDivideAndConquer(int a[], int num, int l, int r, int& cnt)
{
	if (l == r && a[l] < num)
	{
		cnt++;
		return;
	}
	else if (l >= r)
	{
		return;
	}
	int mid = (l + r) / 2;
	countDivideAndConquer(a, num, l, mid - 1, cnt);
	if (a[mid] < num)
	{
		cnt++;
		countDivideAndConquer(a, num, mid + 1, r, cnt);
	}
	else 
	{
		countDivideAndConquer(a, num, mid + 1, r, cnt);
	}
}
int countInversion(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int cnt = 0;
		countDivideAndConquer(a, a[i], i + 1, n - 1, cnt);
		count = count + cnt;
	}
	return count;
}
int main()
{
	int a[100];
	int n;
	InputArray(a, n);
	cout << countInversion(a, n);
} 