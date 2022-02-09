#include<bits/stdc++.h>

using namespace std;

struct point
{
    int z, y, x;
    int day;
};

int N, M, H;
int tomato[101][101][101];
bool visited[101][101][101];

int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

int ans = 0;
int be_ripe = 0;
int expected_ripe = 0;

queue<struct point> q;

void bfs()
{
    while(!q.empty())
    {
        struct point new_point = q.front();
        q.pop();

        if(ans < new_point.day)
            ans = new_point.day;
        
        // cout << new_point.z << " " << new_point.y << " " << new_point.x << " " << endl;

        for(int i = 0; i < 6; ++i)
        {
            int new_dz = new_point.z + dz[i];
            int new_dy = new_point.y + dy[i];
            int new_dx = new_point.x + dx[i];
            int new_day = new_point.day + 1;
            // Out Of Bound..
            if(!(0 <= new_dx && new_dx < N 
                && 0 <= new_dy && new_dy < M
                && 0 <= new_dz && new_dz < H))
            {
                continue;    
            }

            if(visited[new_dz][new_dy][new_dx] == false)
            {
                visited[new_dz][new_dy][new_dx] = true;
                be_ripe++;

                q.push({
                    .z=new_dz,
                    .y=new_dy,
                    .x=new_dx,
                    .day=new_day
                });
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M >> H;

    expected_ripe = M*N*H;
    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            for(int k = 0; k < N; ++k)
            {
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == -1)
                {
                    visited[i][j][k] = true;
                    expected_ripe--;
                }
                else if(tomato[i][j][k] == 1)
                {
                    visited[i][j][k] = true;
                    be_ripe++;
                    q.push({
                        .z=i, 
                        .y=j, 
                        .x=k,
                        .day=0
                    });
                }
            }
        }
    }

    bfs();

    if(be_ripe != expected_ripe)
        cout << -1 << endl;
    else
    {
        cout << ans << endl;
    }

    return 0;
}