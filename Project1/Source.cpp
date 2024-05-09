#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

bool check(int a[1000], int N, int L, long long H)
{
	long long wooden = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] > H)
		{
			wooden = wooden + a[i] - H;
		}
	}
	return wooden >= L;
}
int main()
{
	int N, L; cin >> N >> L;
	int a[1000];
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	long long left = 0, right = *max_element(a, a + N);
	long long res = 0;
	while (left <= right)
	{
		long long mid = (right + left) / 2;
		if (check(a, N, L, mid) == true)
		{
			res = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << res;
}
