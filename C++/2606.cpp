#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

int G[105][105];
int visited[105];
int T, N;
int cnt;
queue<int> q;

void BFS(int v)
{
	int p;
	q.push(v);
	visited[v] = 1;
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		cnt++;
		for(int i = 1; i <= N; ++i)
		{
			if(visited[i] == 0 && G[p][i] == 1)
			{
				q.push(i);
				visited[i] = 1;
			}

		}
	}

}

int main(void)
{
	cin >> N;
	cin >> T;
	int v1, v2;
	for(int i =0; i < T; ++i)
	{
		cin >> v1 >> v2;
		G[v1][v2] = G[v2][v1] = 1;
	}

	BFS(1);

	cout << cnt-1 << endl;

	return 0;
}