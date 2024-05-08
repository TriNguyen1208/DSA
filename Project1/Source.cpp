#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int b[100];
	multiset<int>ms;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		ms.insert(x);
	}
	for (int j = 0; j < m; j++)
	{
		cin >> b[j];
	}
	for (int i = 0; i < m; i++)
	{
		auto it = ms.lower_bound(b[i]);
		if (*it == b[i])
		{
			cout << *it << " ";
			ms.erase(it);
		}
		else
		{
			if (it == ms.begin())
			{
				cout << -1 << " ";
			}
			else
			{
				it--;
				cout << *it << " ";
				ms.erase(it);
			}
		}
	}
	return 0;
}
