#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int G[1005][1005];
int visited[1005];

int N, M, V;

void DFS(int v)
{
	cout << v << ' ';
	visited[v] = 1;
	for(int i = 1; i <= N; ++i)
	{
		if(visited[i] == 0 && G[v][i] == 1)
			DFS(i);
	}
}

void BFS(int v)
{
	queue<int> Q;
	Q.push(v);
	visited[v] = 1;
	while(!Q.empty())
	{
		v = Q.front();
		Q.pop();
		cout << v << ' ';
		for(int i = 1; i <= N; ++i)
		{
			if(visited[i] == 0 && G[v][i] == 1)
			{
				Q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;
	int v1, v2;

	for(int i = 0; i < M; ++i)
	{
		cin >> v1 >> v2;
		G[v1][v2] = G[v2][v1] = 1;
	}
	DFS(V);
	memset(visited, 0, sizeof(visited));
	cout << endl;
	BFS(V);

	return 0;
}