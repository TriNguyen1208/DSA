#include<iostream>
using namespace std;

int main()
{
	int mod = 1e9 + 7;
	int N; cin >> N;
	int a[5];
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	int res = 0;
	for (int x : a)
	{
		res = res + x;
		res %= mod;
	}
	cout << res;
}
//5
//534 7 669 826 610