// #include<bits/stdc++.h>
#include<iostream>
#include<deque>
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define EMPTY 0
#define WALL 1
#define APPLE 2

using namespace std;

typedef pair<int, int> pii;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

typedef struct info{
    int y, x;
    unsigned int direction;
}info;

class earthworm{

private:
    deque< info > dq;
    int board[105][105] = {0};
    int N, time = 0;

public:
    earthworm(int N) {
        this->set_board(N);

        // starting point
        dq.push_front({1, 1, 0});
        board[1][1] = 1;
        
    }

    void set_board(int N)
    {
        this->N = N;
        for(int i = 0; i <= N+1; i++)
        {
            for(int j = 0; j <= N+1; j++)
            {
                if(i == 0 || i == N+1 || j == 0 || j == N+1)
                {
                    board[i][j] = WALL;
                }
            }
        }
    }

    void put_apple(int y, int x)
    {
        board[y][x] = 2; // APPLE
    }

    void move(int time, char D)
    {
        while(this->time < time)
        {
            this->time += 1;
            info tmp = dq.front();
            
            if(board[tmp.y + dy[tmp.direction]][tmp.x + dx[tmp.direction]] == EMPTY) // empty space
            {
                info next = { 
                    .y = tmp.y + dy[tmp.direction],
                    .x = tmp.x + dx[tmp.direction],
                    .direction = tmp.direction
                };

                board[next.y][next.x] = WALL;
                
                dq.push_front( next );
                
                tmp = dq.back();
                dq.pop_back();
                board[tmp.y][tmp.x] = EMPTY;
            }
            else if(board[tmp.y + dy[tmp.direction]][tmp.x + dx[tmp.direction]] == WALL) // Oops
            {
                cout << this->time << endl;
                exit(0);
            }
            else if(board[tmp.y + dy[tmp.direction]][tmp.x + dx[tmp.direction]] == APPLE) // APPLE!
            {
                info next = { 
                    .y = tmp.y + dy[tmp.direction],
                    .x = tmp.x + dx[tmp.direction],
                    .direction = tmp.direction
                };
                board[next.y][next.x] = 1;
                dq.push_front( next );
            }
        }

        if(D == 'D')
            dq.front().direction = (dq.front().direction+1+4)%4;
        else if(D == 'L')
            dq.front().direction = (dq.front().direction-1+4)%4;
        
    }
};

int main(void)
{
    IO

    int N, K, L;
    int x, y;
    int t;
    char d;
    cin >> N;
    earthworm worm(N);

    cin >> K;
    // put apple
    while(K--)
    {
        cin >> y >> x;
        worm.put_apple(y, x);
    }

    cin >> L;

    while(L--)
    {
        cin >> t >> d;
        worm.move(t, d);
    }

    // end.>?
    worm.move(9999, ' ');

    return 0;
}