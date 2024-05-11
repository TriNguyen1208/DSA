#include<iostream>
using namespace std;

void Try(int x[100], int mask[100], int n, int start = 0)
{
	if (start == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << x[i];
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (mask[i] == 0)
		{
			mask[i] = 1;
			x[start] = i;
			Try(x, mask, n, start + 1);
			mask[i] = 0;
		}
	}
}
int main()
{
	int x[100] = { 0 };
	int mask[100] = { 0 };
	Try(x, mask, 5);
}