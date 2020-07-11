#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int N;
int A[105][105];
bool visited[105][105];

int save = 1;
int cnt;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void UP();
void check();
void DFS(int y, int x);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			cin >> A[i][j];
		}
	}

	for(int i = 2; i <= 100; ++i)
	{
		UP();
		check();
		if(cnt == 0)
			break;
		if(save < cnt)
			save = cnt;
		cnt = 0;
		memset(visited, 0, sizeof(visited));
	}

	cout << save << endl;

	return 0;
}

void UP()
{
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			A[i][j] -= 1;
}

void check()
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			if(A[i][j] > 0 && visited[i][j] == 0)
			{
				DFS(i, j);
				cnt++;
			}
		}
	}
}

void DFS(int y, int x)
{
	visited[y][x] = 1;

	for(int i = 0; i < 4; ++i)
	{
		int NX = dx[i] + x;
		int NY = dy[i] + y;

		if(!(0 <= NX && NX < N && 0 <= NY && NY < N))
			continue;
		else if(visited[NY][NX] == 0 && A[NY][NX] > 0)
		{
			DFS(NY, NX);
		}
	}
}