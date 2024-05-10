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
void BackTrack(int a[], int partition[], int n, int k, int& max_min, int start = 0, int current = 0)
{
	if (start == n)
	{
		for (int i = 0; i < k; i++)
		{
			if (partition[i] == 0)
			{
				return;
			}
		}
		int sum[100] = { 0 };
		int j = 0;
		for (int i = 0; i < k; i++)
		{
			int k = j;
			for (; k < j + partition[i]; k++)
			{
				sum[i] = sum[i] + a[k];
			}
			j = k;
		}
		max_min = min(max_min, *max_element(sum, sum + k));
		return;
	}
	for (int i = current; i < k; i++)
	{
		partition[i]++;
		BackTrack(a, partition, n, k, max_min, start + 1, i);
		partition[i]--;
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
	int partition[100] = { 0 };
	int max_min = INT_MAX;
	BackTrack(a, partition, n, k, max_min);
	cout << max_min;
}