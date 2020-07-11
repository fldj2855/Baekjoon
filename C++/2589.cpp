#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef struct Data
{
	int y;
	int x;
	int count;
}Data;

int ans;
int N, M;
char B[55][55];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void BFS(int y, int x)
{
	bool visited[55][55];
	memset(visited, 0, sizeof(visited));
	int ny, nx;
	Data p;
	queue<Data> Q;

	Q.push({y, x, 0});
	visited[y][x] = 1;

	while(!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if(ans < p.count)
			ans = p.count;

		for(int i = 0; i < 4; ++i)
		{
			ny = p.y + dy[i];
			nx = p.x + dx[i];

			if(!(0 <= nx && nx < M && 0 <= ny && ny < N))
				continue;

			if(B[ny][nx] == 'L' && visited[ny][nx] == 0)
			{
				Q.push({ny, nx, p.count+1});
				visited[ny][nx] = 1;
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%s", B[i]);

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if(B[i][j] == 'L')
				BFS(i, j);
		}
	}

	cout << ans << endl;

	return 0;
}