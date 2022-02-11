#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef pair<int,int> pii;
int N, M;

struct arbitrary_ice_point
{
    int x, y;
} P={-1,-1};

bool visited[302][302];
int ice_map[302][302];
int near_water[302][302];
int ice_total = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs()
{
    int ret = 0;

    queue<pii> Q;
    Q.push({P.y, P.x});
    ret = 1;
    visited[P.y][P.x] = true;
    
    while(!Q.empty())
    {
        pii tmp = Q.front();
        Q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int new_y = tmp.first + dy[i];
            int new_x = tmp.second + dx[i];
            if(!(1 <= new_y && new_y <= N && 1 <= new_x && new_x <= M))
                continue;
            
            if(visited[new_y][new_x])
                continue;
            
            visited[new_y][new_x] = true;
            Q.push({new_y, new_x});
            ret++;
        }
    }

    return ret != ice_total;
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int ans = 0;
    cin >> N >> M;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            cin >> ice_map[i][j];
            if(ice_map[i][j] && P.y == -1 && P.x == -1)
            {
                P.y = i;
                P.x = j;
            }

            visited[i][j] = !ice_map[i][j];
            
            if(ice_map[i][j])
                ice_total++;
        }
    }

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            if(ice_map[i][j])
            {
                for(int z = 0; z < 4; ++z)
                {
                    if(1 <= i+dy[z] && i+dy[z] <= N && 1 <= j+dx[z] && j+dx[z] <= M)
                        near_water[i][j] += !ice_map[i+dy[z]][j+dx[z]];
                }
            }
        }
    }

    while(ice_total)
    {

        // check ice
        if(bfs())
            break;

        // proceed 1 year..
        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= M; ++j)
            {
                if(ice_map[i][j])
                {
                    ice_map[i][j] -= near_water[i][j];
                    if(ice_map[i][j] <= 0)
                    {
                        near_water[i][j] = 0;
                        ice_map[i][j] = 0;
                        ice_total--;
                    }
                }
                visited[i][j] = !ice_map[i][j];
            }
        }

        // renew newar_water
        for(int i = 1; i <= N; ++i)
        {
            for(int j = 1; j <= M; ++j)
            {
                if(ice_map[i][j])
                {
                    near_water[i][j] = 0;
                    for(int z = 0; z < 4; ++z)
                        if(1 <= i+dy[z] && i+dy[z] <= N && 1 <= j+dx[z] && j+dx[z] <= M)
                            near_water[i][j] += !ice_map[i+dy[z]][j+dx[z]];
                    
                    if(ice_map[P.y][P.x] == 0)
                    {
                        P.y=i;
                        P.x=j;
                    }
                }
            }
        }
        ans+=1;
    }

    cout << (ice_total == 0 ? 0 : ans) << endl;

    return 0;
}