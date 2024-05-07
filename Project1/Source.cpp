#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	int mod = 1e9 + 7;
	int res = 1;
	for (int i = 0; i < M; i++)
	{
		res = res * N;
		res = res % (int)pow(10, K);
	}
	cout << res;
}
//5
//534 7 669 826 610