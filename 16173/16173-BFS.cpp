#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

int Board[4][4];
bool VISIT[4][4];

int N;
int dy[] = {0, 1};
int dx[] = {1, 0};

int BFS()
{
    queue<pii> q;

    q.push(pii(1, 1));

    VISIT[1][1] = true;

    while(!q.empty())
    {
        pii tmp = q.front();
        q.pop();

        // Find!
        if(tmp.first == N && tmp.second == N)
            return 1;

        for(int i = 0; i < 2; ++i)
        {
            int x_moved = tmp.second + Board[tmp.first][tmp.second]*dx[i];
            int y_moved = tmp.first + Board[tmp.first][tmp.second]*dy[i];

            // die!
            if(!(1 <= x_moved && x_moved <= N && 1 <= y_moved && y_moved <= N))
                continue;
            
            // already VISIT
            if(VISIT[y_moved][x_moved])
                continue;

            q.push(pii(y_moved, x_moved));
            VISIT[y_moved][x_moved] = true;

        }
    }


    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            cin >> Board[i][j];
        }
    }

    if(BFS())
        cout << "HaruHaru" << endl;
    else
        cout << "Hing" << endl;
}