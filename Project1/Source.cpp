#include<iostream>
#include<string>
using namespace std;

void BackTrack(string dic[], char A[][10], int K, int M, int N, int word, int indexX, int indexY, int cnt = 1)
{
	if (cnt == dic[word].length())
	{
		cout << dic[word] << " ";
		return;
	}
	//Cheo Trai
	if (indexX - 1 >= 0 && indexY - 1 >= 0 && A[indexX - 1][indexY - 1] == dic[word][cnt])
	{
		BackTrack(dic, A, K, M, N, word, indexX - 1, indexY - 1, cnt + 1);
	}
	//Cheo Phai
	if (indexX - 1 >= 0 && indexY + 1 < N && A[indexX - 1][indexY + 1] == dic[word][cnt])
	{
		BackTrack(dic, A, K, M, N, word, indexX - 1, indexY + 1, cnt + 1);
	}
	//Cheo Trai Xuong
	if (indexX + 1 < M && indexY - 1 >= 0 && A[indexX + 1][indexY - 1] == dic[word][cnt])
	{
		BackTrack(dic, A, K, M, N, word, indexX + 1, indexY - 1, cnt + 1);
	}
	//Cheo Phai Xuong
	if (indexX + 1 < M && indexY + 1 < N && A[indexX + 1][indexY + 1] == dic[word][cnt])
	{
		BackTrack(dic, A, K, M, N, word, indexX + 1, indexY + 1, cnt + 1);
	}
	// Tren
	if (indexX - 1 >= 0 && A[indexX - 1][indexY] == dic[word][cnt])
	{
		BackTrack(dic, A, K, M, N, word, indexX - 1, indexY, cnt + 1);
	}
	//Xuong
	if (indexX + 1 < M && A[indexX + 1][indexY] == dic[word][cnt])
	{
		BackTrack(dic, A, K, M, N, word, indexX + 1, indexY, cnt + 1);
	}
	//Phai
	if (indexY - 1 >= 0 && A[indexX][indexY - 1] == dic[word][cnt])
	{
		BackTrack(dic, A, K, M, N, word, indexX, indexY - 1, cnt + 1);
	}
	//Trai
	if (indexY + 1 < N && A[indexX][indexY + 1] == dic[word][cnt])
	{
		BackTrack(dic, A, K, M, N, word, indexX, indexY + 1, cnt + 1);
	}
}
void Search(string dic[], char A[][10], int K, int M, int N, int word)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] == dic[word][0])
			{
				BackTrack(dic, A, K, M, N, word, i, j);
			}
		}
	}
}
int main()
{
	int K, M, N; cin >> K >> M >> N;
	string dic[100];
	for (int i = 0; i < K; i++)
	{
		cin >> dic[i];
	}
	char A[10][10];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		Search(dic, A, K, M, N, i);
	}
}