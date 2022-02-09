#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

struct user {
    int x, y, z;
    int move;
} ST, EX, USER;

int L, R, C;

int Building[31][31][31];
bool visited[31][31][31];

int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

void bfs()
{
    queue<struct user> q;

    q.push(ST);
    while(!q.empty())
    {
        struct user tmp = q.front();
        q.pop();

        if(tmp.x == EX.x && tmp.y == EX.y && tmp.z == EX.z)
        {
            cout << "Escaped in " << tmp.move << " minute(s)." << endl;
            return;
        }

        for(int i = 0; i < 6; ++i)
        {
            int new_z = tmp.z + dz[i];
            int new_y = tmp.y + dy[i];
            int new_x = tmp.x + dx[i];
            int new_move = tmp.move + 1;
            
            if(!(0 <= new_x && new_x < C
                && 0 <= new_y && new_y < R
                && 0 <= new_z && new_z < L))
            {
                continue;
            }

            if(visited[new_z][new_y][new_x] == false)
            {
                visited[new_z][new_y][new_x] = true;

                q.push({
                    .x=new_x,
                    .y=new_y,
                    .z=new_z,
                    .move=new_move
                });
            }
        }
    }

    cout << "Trapped!" << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);

    while(1)
    {
        memset(Building, 0, 31*31*31);
        memset(visited, 0, 31*31*31);

        cin >> L >> R >> C;
        if(!L && !R && !C)
            break;
        
        for(int i = 0; i < L; ++i)
        {
            for(int j = 0; j < R; ++j)
            {
                string tmp;
                cin >> tmp;
                for(int z = 0; z < C; ++z)
                {
                    Building[i][j][z] = tmp[z];

                    if(tmp[z] == '#')
                        visited[i][j][z] = true;
                    else if(tmp[z] == 'S')
                    {
                        ST.x = z;
                        ST.y = j;
                        ST.z = i;
                        ST.move = 0;
                        visited[i][j][z] = true;
                    }
                    else if(tmp[z] == 'E')
                    {
                        EX.x = z;
                        EX.y = j;
                        EX.z = i;
                    }
                }
            }
        }

        bfs();
    }
}