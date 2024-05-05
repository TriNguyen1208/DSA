#include<iostream>
#include<string>
#include<string.h>
#include<set>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

string Sum(string x1, string x2)
{
	string res = "";
	int cnt1 = x1.length();
	int cnt2 = x2.length();
	while (cnt1 < cnt2)
	{
		res = res + x2[cnt2 - 1];
		cnt2--;
	}
	while (cnt1 > cnt2)
	{
		res = res + x1[cnt1 - 1];
		cnt1--;
	}
	int tmp = 0;
	for (int i = cnt1 - 1; i >= 0; i--)
	{
		int sum = x1[i] - '0' + x2[i] - '0';
		if (sum + tmp >= 10)
		{
			if (i == 0)
			{
				res = res + to_string(sum + tmp);
			}
			else
			{
				res = res + to_string((sum + tmp) % 10);
				tmp = (sum + tmp) / 10;
			}
		}
		else
		{
			res = res + to_string(sum + tmp);
			tmp = 0;
		}
	}
	reverse(res.begin(), res.end());
	return res;
}
//4 4 
//3 1 2 4
//1 1 7 5
//2 3 8 6
//4 2 1 5
void toLower(string& s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
}
bool cmp(pair<string, int>s1, pair<string, int>s2)
{
	if (s1.second < s2.second)
	{
		return true;
	}
	return false;
}
bool checkSymmetry(string word)
{
	int l = 0, r = word.length() - 1;
	while (l <= r)
	{
		if (word[l] != word[r])
		{
			return false;
		}
		l++, r--;
	}
	return true;
}
int main()
{
	string s;
	getline(cin, s);
	vector<pair<string, int>>v;
	stringstream ss(s);
	string word;
	while (ss >> word)
	{
		if (checkSymmetry(word) == true)
		{
			v.push_back({ word, word.length() });
		}
	}
	stable_sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " ";
	}
}
