#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++)
	{
		int power_dragon, bonus_score;
		cin >> power_dragon >> bonus_score;
		v.push_back({ power_dragon, bonus_score });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		if (s <= v[i].first)
		{
			cout << "NO";
			return 0;
		}
		s = s + v[i].second;
	}
	cout << "YES";
}
