#include<iostream>
using namespace std;

bool IsCorrect(int mask[][100], int indexX, int indexY)
{
	//Check horizontal
	for (int i = 0; i < 8; i++)
	{
		if (mask[indexX][i] == 1)
		{
			return false;
		}
	}
	//Check vertical
	for (int i = 0; i < 8; i++)
	{
		if (mask[i][indexY] == 1)
		{
			return false;
		}
	}
	//Check main diagonal
	int i = indexX, j = indexY;
	while (i < 8 && j < 8)
	{
		if (mask[i][j] == 1)
		{
			return false;
		}
		i++, j++;
	}
	i = indexX, j = indexY;
	while (i >= 0 && j >= 0)
	{
		if (mask[i][j] == 1)
		{
			return false;
		}
		i--, j--;
	}
	//Check secondary diagonal
	i = indexX, j = indexY;
	while (i >= 0 && j <= 8)
	{
		if (mask[i][j] == 1)
		{
			return false;
		}
		i--, j++;
	}
	i = indexX, j = indexY;
	while (j >= 0 && i <= 8)
	{
		if (mask[i][j] == 1)
		{
			return false;
		}
		j--, i++;
	}
	return true;
}
void backtrack(int a[][100], int mask[][100], int& Max, int sum = 0, int cnt = 0, int indexX = 0)
{
	if (cnt == 8)
	{
		Max = max(Max, sum);
		return;
	}
	for (int i = 0; i < 8; i++)//run col
	{
		if (mask[indexX][i] == 0 && IsCorrect(mask, indexX, i) == true)
		{
			mask[indexX][i] = 1;
			backtrack(a, mask, Max, sum + a[indexX][i], cnt + 1, indexX + 1);
			mask[indexX][i] = 0;
		}
	}
}
int main()
{
	int a[100][100];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> a[i][j];
		}
	}
	int mask[100][100] = { 0 };
	int max = 0;
	backtrack(a, mask, max);
	cout << max;
}