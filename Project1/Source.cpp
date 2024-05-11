#include<iostream>
using namespace std;

void Try(int a[], int mask[], int n, int k, int start = 0)
{
	if (start == k)
	{
		for (int i = 0; i < k; i++)
		{
			cout << a[i];
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (mask[i] == 0)
		{
			mask[i] = 1;
			a[start] = i;
			Try(a, mask, n, k, start + 1);
			mask[i] = 0;
		}
	}
}
int main()
{
	int x[100] = { 0 };
	int mask[100] = { 0 };
	Try(x, mask, 5, 3);
}