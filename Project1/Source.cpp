#include<iostream>
using namespace std;

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
void HorsePatrol(int a[100][100], int N, int indexX = 0, int indexY = 0, int count = 0)
{
	if (count == N * N - 1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		int i1 = indexX + dx[i];
		int j1 = indexY + dy[i];
		if (i1 >= 0 && i1 < N && j1 >= 0 && j1 < N && a[i1][j1] == 0)
		{
			a[i1][j1] = count + 2;
			HorsePatrol(a, N, i1, j1, count + 1);
			a[i1][j1] = 0;
		}
	}
}
void HorsePatrolAdvance(int a[100][100], int N, int indexX = 0, int indexY = 0, int count = 0)
{
	if (count == N * N - 1)
	{
		for (int i = 0; i < 8; i++)
		{
			int i1 = indexX + dx[i];
			int j1 = indexY + dy[i];
			if (i1 >= 0 && i1 < N && j1 >= 0 && j1 < N && a[i1][j1] == 1)
			{
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						cout << a[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
				system("pause");
				break;
			}
		}
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		int i1 = indexX + dx[i];
		int j1 = indexY + dy[i];
		if (i1 >= 0 && i1 < N && j1 >= 0 && j1 < N && a[i1][j1] == 0)
		{
			a[i1][j1] = count + 2;
			HorsePatrolAdvance(a, N, i1, j1, count + 1);
			a[i1][j1] = 0;
		}
	}
}
int main()
{
	int N; cin >> N;
	int a[100][100] = { 0 };
	a[0][0] = 1;
	HorsePatrolAdvance(a, N);
}