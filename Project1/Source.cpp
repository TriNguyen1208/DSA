#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
	priority_queue<int>qe;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		qe.push(x);
	}
	int cost = 0;
	while (qe.size() != 1)
	{
		int x = qe.top();
		qe.pop();
		int y = qe.top();
		qe.pop();
		cost = cost + (x + y);
		qe.push(x + y);
	}
	cout << cost;
}
