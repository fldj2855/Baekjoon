#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int M, N, K, T;
int cnt;
int board[55][55];

int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, 1, -1};

void dfs(int y, int x)
{
	board[y][x] = 2;
	for(int i = 0; i < 4; ++i)
	{
		if(board[y+Y[i]][x+X[i]] == 1)
			dfs(y+Y[i], x+X[i]);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> T;
	for(int i = 0; i < T; ++i)
	{
		cnt = 0;
		cin >> M >> N >> K;
		for(int j = 0; j < K; ++j)
		{
			cin >> x >> y;
			board[y+1][x+1] = 1;
		}
		
		for(int j = 1; j < N+1; ++j)
		{
			for(int k = 1; k < M+1; ++k)
			{
				if(board[j][k] == 1)
				{
					dfs(j, k);
					cnt++;
				}
			}
		}

		cout << cnt << endl;

		for(int j = 0; j < 55; ++j)
			for(int k = 0; k < 55; ++k)
				board[j][k] = 0;
	}

	return 0;
}