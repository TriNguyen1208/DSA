#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	//python
	string t = "python";
	int idx = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == t[idx])
		{
			idx++;
		}
	}
	if (idx == 6)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}