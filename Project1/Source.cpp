#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;

void ChangeToLower(string& word)
{
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}
}
bool cmp(string s1, string s2)
{
	if (s1 < s2)
	{
		return false;
	}
	return true;
}
int main()
{
	int n; cin >> n;
	vector<string>v;
	for (int i = 0; i < n; i++)
	{
		string tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
}