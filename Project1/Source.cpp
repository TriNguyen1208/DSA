#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int>v;
	int luck = 0;
	for (int i = 0; i < n; i++)
	{
		int l, t; cin >> l >> t;
		if (t == 0)
		{
			luck = luck + l;
		}
		else
		{
			v.push_back(l);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++)
	{
		if (i < k)
		{
			luck = luck + v[i];
		}
		else
		{
			luck = luck - v[i];
		}
	}
	cout << luck;
}