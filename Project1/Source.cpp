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
int main()
{
	initFibo();
	int n; long long k;
	cin >> n >> k;
	cout << fiboString(n, k);
}