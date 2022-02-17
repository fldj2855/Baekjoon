#include<bits/stdc++.h>
#define endl '\n'
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int board[501][501];
int dp[501][501];

int M, N;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dfs_dp(int y, int x)
{
    if(dp[y][x] > 0)
        return dp[y][x];

    if(dp[y][x] == -1)
    {
        dp[y][x] = 0;
        for(int i = 0; i < 4; ++i)
        {
            int new_y = y+dy[i];
            int new_x = x+dx[i];
            if(!(0 <= new_y && new_y < M && 0 <= new_x && new_x < N))
                continue;
            
            if(board[y][x] > board[new_y][new_x])
            {
                // cout << new_y << " " << new_x << endl;
                dp[y][x] += dfs_dp(new_y, new_x);
            }
        }
    }

    return dp[y][x];
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> M >> N;

    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            dp[i][j]=-1;
        }

    dp[M-1][N-1] = 1;
    cout << dfs_dp(0, 0) << endl;   
    
}