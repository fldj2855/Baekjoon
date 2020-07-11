#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int, int> pii;

queue<pii> q;

int B[1005][1005];
int N, M;

void BFS()
{
	int X[4] = {0, 0, 1, -1};
	int Y[4] = {1, -1, 0, 0};

	while(!q.empty())
	{
		pii p = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i)
		{
			int NY = p.first+ Y[i];
			int NX = p.second + X[i];

			if(0 <= NY && NY < N && 0 <= NX && NX < M)
			{
				if(B[NY][NX] != -1 && !B[NY][NX])
				{
					B[NY][NX] = B[p.first][p.second] + 1;
					q.push(pii(NY, NX));
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N;

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			cin >> B[i][j];
			if(B[i][j] == 1)
				q.push(pii(i,j));
		}
	}
	if(!q.empty())
		BFS();
	else
	{
		cout << -1 << endl;
		return 0;
	}

	int MAX = 0;
	int flag = 0;

	for(int i = 0;!flag && i < N; ++i)
	{
		for(int j = 0;!flag && j < M; ++j)
		{
			if(B[i][j] == 0)
				flag = 1;
			if(MAX < B[i][j])
				MAX = B[i][j];
		}
	}

	if(flag)
		cout << -1 << endl;
	else if(MAX == 0)
		cout << 0 << endl;
	else
		cout << MAX-1 << endl;

	return 0;
}