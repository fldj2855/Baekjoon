#include<bits/stdc++.h>

int dp[1025][1025];
int A[1024][1024];

int main(void)
{
    int N, M;
    int x1, x2, y1, y2;
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            scanf("%d", &A[i-1][j-1]);
            dp[i][j] = A[i-1][j-1] - dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1];
        }
    }

    // for(int i = 0; i <= N; ++i)
    // {
    //     for(int j = 0; j <= N; ++j)
    //     {
    //         printf("%3d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    while(M--)
    {
        scanf("%d %d %d %d", &x1, &x2, &y1, &y2);

        // printf("%d %d %d %d\n",dp[y1][y2] , dp[y1][x2 - 1] , dp[x1 - 1][y2] , dp[x1-1][x2-1] );
        printf("%d\n", dp[y1][y2] - dp[y1][x2 - 1] - dp[x1 - 1][y2] + dp[x1-1][x2-1]);
    }
}