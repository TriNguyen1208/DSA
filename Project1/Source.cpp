#include<iostream>
using namespace std;

void Backtrack(int a[][100], char save[], int N, int indexX = 0, int indexY = 0, int cnt = 0)
{
	if (indexX == N - 1 && indexY == N - 1)
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << save[i];
		}
		cout << "   ";
		return;
	}
	//Go down
	if (indexX + 1 >= 0 && indexX + 1 < N && a[indexX + 1][indexY] == 1)
	{
		save[cnt] = 'D';
		Backtrack(a, save, N, indexX + 1, indexY, cnt + 1);
	}
	if (indexY + 1 >= 0 && indexY + 1 < N && a[indexX][indexY + 1] == 1)
	{
		save[cnt] = 'R';
		Backtrack(a, save, N, indexX, indexY + 1, cnt + 1);
	}
}
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int N; cin >> N;
		int a[100][100];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> a[i][j];
			}
		}
		char save[100];
		Backtrack(a, save, N);
	}
}