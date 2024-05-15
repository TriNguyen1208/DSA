#include<iostream>
#include<stack>
using namespace std;

bool check(string s)
{
	stack<char>st;
	for (char x : s)
	{
		if (x == '[' || x == '{' || x == '(')
		{
			st.push(x);
		}
		else
		{
			if (st.empty())
			{
				return false;
			}
			char y = st.top();
			st.pop();
			if ((x == ')' && y != '(') || (x == '}' && y != '{') || (x == ']' && y != '['))
			{
				return false;
			}
		}
	}
	if (st.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void backtrack(string s, string tmp, int n, int cnt = 0)
{
	if (cnt == n)
	{
		if (check(tmp) == true)
		{
			for (int i = 0; i < n; i++)
			{
				cout << tmp[i];
			}
			cout << " ";
		}
		return;
	}
	for (int i = 0; i < s.size(); i++)
	{
		tmp = tmp + s[i];
		backtrack(s, tmp, n, cnt + 1);
		tmp.pop_back();
	}
}
int main()
{
	string s = "()[]{}";
	string tmp = "";
	backtrack(s, tmp, 6);
}