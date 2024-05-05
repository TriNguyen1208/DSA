#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<sstream>
using namespace std;

void ChangeToLower(string& word)
{
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}
}
int main()
{
	string S;
	getline(cin, S);
	string T;
	getline(cin, T);
	ChangeToLower(S);
	ChangeToLower(T);
	set<string>s;
	set<string>t;
	stringstream ss(S);
	stringstream st(T);
	string word;
	while (ss >> word)
	{
		s.insert(word);
	}
	while (st >> word)
	{
		t.insert(word);
	}
	set<string>total;
	for (set<string>::iterator it = s.begin(); it != s.end(); it++)
	{
		if (t.find(*it) == t.end())
		{
			total.insert(*it);
		}
	}
	for (set<string>::iterator it = t.begin(); it != t.end(); it++)
	{
		if (t.find(*it) == t.end())
		{
			total.insert(*it);
		}
	}
	for (auto it = total.begin(); it != total.end(); it++)
	{
		cout << *it << " ";
	}
}