#include<iostream>
using namespace std;

int a[100];
int mask[100];
bool IsPrime(int x)
{
	if (x < 2)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool IsAscending(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i + 1] < a[i])
		{
			return false;
		}
	}
	return true;
}
void BackTrack(int n, int p, int s, int& solan, int sum = 0, int cnt = 0)
{
	if (cnt == n && sum == s)
	{
		if (IsAscending(a, n) == true)
		{
			solan++;
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = p + 1; i < s; i++)
	{
		if (IsPrime(i) && sum + i <= s && mask[i] == 0)
		{
			a[cnt] = i;
			mask[i] = 1;
			BackTrack(n, p, s, solan, sum + i, cnt + 1);
			mask[i] = 0;
			a[cnt] = 0;
		}
	}
}
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n, p, s; cin >> n >> p >> s;
		int solan = 0;
		BackTrack(n, p, s, solan);
	}
}