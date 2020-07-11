#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

char O['z'-'a'+1];
char board[21][21];
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
int cnt;
int R,C;

void dfs(int y, int x, int c);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for(int i = 0; i < R; ++i)
		cin >> board[i];

	dfs(0, 0, 1);

	cout << cnt << endl;
	return 0;
}

void dfs(int y, int x, int c)
{
	char tmp = board[y][x];
	O[tmp-'A'] = 1;
	board[y][x] = '\0';
	if(cnt < c)
		cnt = c;

	for(int i = 0; i < 4; ++i)
	{
		if(0 <= y+Y[i] && y+Y[i] < R && 0 <= x+X[i] && x+X[i] < C)
		{
			if(!O[board[y+Y[i]][x+X[i]]-'A'] && board[y+Y[i]][x+X[i]])
				dfs(y+Y[i], x+X[i], c+1);
		}
	}
	board[y][x] = tmp;
	O[tmp-'A'] = 0;
}