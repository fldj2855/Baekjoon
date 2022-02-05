#include<bits/stdc++.h>
#define endl '\n'
#define BLACK 1
#define WHITE 2

using namespace std;

int board[21][21];
int visitmap[21][21];

int N, B, W;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int DFS(int y, int x, int *status)
{
    int ans = 1;

    visitmap[y][x] = true;


    for(int i = 0; i < 4; ++i)
    {
        if(!(1 <= y + dy[i] && y + dy[i] <= N && 1 <= x + dx[i] && x + dx[i] <= N))
            continue;
        
        if(board[y+dy[i]][x+dx[i]] == BLACK)
            *status |= BLACK;
        else if(board[y+dy[i]][x+dx[i]] == WHITE)
            *status |= WHITE;
        
        if(!visitmap[y+dy[i]][x+dx[i]])
        {
            ans += DFS(y+dy[i], x+dx[i], status);
        }
    }

    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int y, x;
    int black_house = 0, white_house = 0;

    while(!cin.eof())
    {

        cin >> N;

        if(!N)
            break;
        
        for(int i = 0; i <= N; ++i)
            for(int j = 0; j <= N; ++j)
                visitmap[i][j] = board[i][j] = 0;

        cin >> B >> W;

        // black
        for(int i = 0; i < B; ++i)
        {
            cin >> y >> x;
            board[y][x] = BLACK;
            visitmap[y][x] = true;
        }

        // white
        for(int i = 0; i < W; ++i)
        {
            cin >> y >> x;
            board[y][x] = WHITE;
            visitmap[y][x] = true;
        }

        black_house = white_house = 0;
        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= N; ++j)
            {
                int status = 0;
                if(!board[i][j] && !visitmap[i][j])
                {
                    int r = DFS(i, j, &status);
                    if((status & BLACK) && (status & WHITE))
                        continue;
                    else if((status & BLACK))
                        black_house += r;
                    else if((status & WHITE))
                        white_house += r;
                }
            }
        }

        if(black_house == white_house)
            cout << "Draw" << endl;
        else if(black_house < white_house)
            cout << "White wins by " << white_house - black_house << endl;
        else
            cout << "Black wins by " << black_house - white_house << endl;
    }
    return 0;
}