#include<bits/stdc++.h>

using namespace std;

int N, M, K;
char _MAP[105][105];
char Find[6];
int Find_len;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int DFS(int y, int x)
{
	int tmp_x, tmp_y;
	for(int i = 1; i < Find_len; ++i)
	{
		
		if()
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int res = 0;
	cin >> N >> M >> K;

	for(int i = 0; i < N; ++i)
		cin >> _MAP[i];

	cin >> Find;
	Find_len = Find.length();

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if(_MAP[i][j] == Find[0])
				res += DFS(i, j);
		}
	}

	cout << res << endl;

	return 0;
}