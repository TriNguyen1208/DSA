#include<iostream>
#include<string>
#include<string.h>
#include<set>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

string updateEmail(string email)
{
	string res = "";
	for (int i = 0; i < email.length(); i++)
	{
		email[i] = tolower(email[i]);
	}
	vector<string>v;
	stringstream ss(email);
	string word;
	while (ss >> word)
	{
		v.push_back(word);
	}
	res = res + v[v.size() - 1];
	for (int i = 0; i < v.size() - 1; i++)
	{
		res = res + v[i][0];
	}
	res = res + "@xyz.edu.vn";
	return res;
}
string updatePassword(string password)
{
	string res;
	stringstream ss(password);
	string word;
	while (getline(ss, word, '/'))
	{
		res = res + to_string(stoi(word));
	}
	return res;
}
int main()
{
	int n; cin >> n;
	while (n--)
	{
		cin.ignore();
		string info;
		getline(cin, info);
		vector<string>v;
		stringstream ss(info);
		string word;
		while (ss >> word)
		{
			v.push_back(word);
		}
		string email = "";
		string password = "";
		for (int i = 0; i < v.size() - 1; i++)
		{
			email = email + v[i] + " ";
		}
		email.pop_back();
		password = v[v.size() - 1];

		email = updateEmail(email);
		password = updatePassword(password);
		cout << email << endl << password;
	}
}
