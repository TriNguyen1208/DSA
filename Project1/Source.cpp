#include<iostream>
#include<string>
#include<string.h>
#include<set>
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

int main()
{
	string s;
	getline(cin, s);
	int cnt[26] = { 0 };
	for (int i = 0; i < s.length(); i++)
	{
		cnt[s[i] - 'a'] = 1;
	}
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == 0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	//Hello
}
