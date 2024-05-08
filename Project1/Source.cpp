#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main()
{
	vector<pair<int, int>>v;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start;
		v.push_back({ start, 1 });
		cin >> end;
		v.push_back({ end, -1 });
	}
	sort(v.begin(), v.end());
	int res = 0;
	int max = INT_MIN;
	for (int i = 0; i < v.size(); i++)
	{
		res = res + v[i].second;
		if (res > max)
		{
			max = res;
		}
	}
	cout << max;
}
