#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int N, M;

int save;
int cnt;

int board[10][10];
int copy_board[10][10];
int visited[10][10];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void search();
void DFS(int y, int x);

int main(void)
{
	cin >> N >> M;
	for(int i =0 ; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	for(int i = 0; i < N*M-2; ++i)
	{
		if(board[i/M][i%M] != 0)
			continue;
		board[i/M][i%M] = 1;
		for(int j = i+1; j < N*M-1; ++j)
		{
			if(board[j/M][j%M] != 0)
				continue;

			board[j/M][j%M] = 1;
			for(int z = j+1; z < N*M; ++z)
			{
				if(board[z/M][z%M] != 0)
					continue;

				board[z/M][z%M] = 1;
				search();
				board[z/M][z%M] = 0;
				memset(visited, 0, sizeof(visited));
				memset(copy_board, 0, sizeof(copy_board));
			}
			board[j/M][j%M] = 0;
		}
		board[i/M][i%M] = 0;
	}

	cout << save << endl;

	return 0;
}

void search()
{
	memcpy(copy_board, board, sizeof(copy_board));

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if(copy_board[i][j] == 2)
			{
				DFS(i, j);
			}
		}
	}

	int cnt = 0;
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if(!copy_board[i][j])
				cnt++;
		}
	}

	if(save < cnt)
		save = cnt;	
}

void DFS(int y, int x)
{
	visited[y][x] = 1;
	copy_board[y][x] = 2;

	int nx, ny;

	for(int i = 0; i < 4; ++i)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if(!(0 <= nx && nx < M && 0 <= ny && ny < N))
			continue;
		if(visited[ny][nx])
			continue;
		if(copy_board[ny][nx] == 0)
			DFS(ny, nx);
	}
}