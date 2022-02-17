#include<bits/stdc++.h>

using namespace std;

int direction[][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};
int d;

int ry, rx;

int N, M;
int board[51][51];
bool visited[51][51];

void printing()
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
            cout << visited[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int running()
{
    int clean_cnt = 0;
    int new_y, new_x;

    while(true)
    {
        // printing();
        // 1
        if(!visited[ry][rx])
        {
            visited[ry][rx] = true;
            clean_cnt += 1;
        }

        if(visited[ry+1][rx] && visited[ry-1][rx] && visited[ry][rx+1] && visited[ry][rx-1])
        {
            new_y = ry - direction[d][0];
            new_x = rx - direction[d][1];
            if(board[new_y][new_x])
            {
                break;
            }
            else
            {
                ry = new_y;
                rx = new_x;
                continue;
            }
        }

        new_y = ry + direction[(d+3)%4][0];
        new_x = rx + direction[(d+3)%4][1];
        d = (d+3)%4;
        if(!visited[new_y][new_x])
        {
            ry=new_y;
            rx=new_x;
            continue;
        }
        
    }

    return clean_cnt;
}

int main(void)
{
    cin >> N >> M;
    cin >> ry >> rx >> d;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if(board[i][j])
                visited[i][j] = 1;
        }
    
    cout << running();

    return 0;
}