#include<bits/stdc++.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void)
{
    int N, M;
    unsigned short board[1005][1005] = {0};
    unsigned short ans;
    while(1){
        ans = 0;
        scanf("%d %d", &N, &M);
        if(!N && !M)
            break;

        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= M; ++j)
            {
                scanf("%hu", &board[i][j]);
                if(board[i][j] == 1)
                {
                    board[i][j] = MIN(board[i-1][j], MIN(board[i][j-1], board[i-1][j-1]))+1;
                    ans = MAX(ans, board[i][j]);
                }
            }
        }

        printf("%hu\n", ans);
    }

    
}