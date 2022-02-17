#include<bits/stdc++.h>
#define endl '\n'
#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int N;
int Array[101][101];
bool visited[101][101];

int minvalue = INF, maxvalue = -INF;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int y, int x, int &flag, int rqmin, int rqmax)
{
    visited[y][x] = true;
    if(y == N-1 && x == N-1)
    {
        flag = 1;
        return;
    }

    for(int i = 0; !flag && i < 4; ++i)
    {
        int new_y = y + dy[i];
        int new_x = x + dx[i];

        if(!(0 <= new_y && new_y < N && 0 <= new_x && new_x < N))
            continue;
            
        if(!visited[new_y][new_x] && rqmin <= Array[new_y][new_x] && Array[new_y][new_x] <= rqmax)
            dfs(new_y, new_x, flag, rqmin, rqmax);
    }

    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;
    
    vector<int> v;

    int l, r, flag, mid;

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> Array[i][j];
            if(Array[i][j] < minvalue)
                minvalue = Array[i][j];
            if(Array[i][j] > maxvalue)
                maxvalue = Array[i][j];
        }
    }

    l = 0, r = 200;
    int save = INF;
    bool range_over;
    while(l <= r)
    {
        
        range_over = true;
        flag = 0;
        mid = (l+r)/2;
        
        // cout << mid << endl;
        for(int i = minvalue; !flag && i+mid <= maxvalue; ++i)
        {
            memset(visited, 0, sizeof(visited));
            range_over = false;
            // cout << i << " " << i+mid << endl;
            if(i <= Array[0][0] && Array[0][0] <= i+mid)
                dfs(0, 0, flag, i, i+mid);
        }

        // range is over
        // or can reach (1,1) to (n,n)
        if(range_over || flag)
        {
            if(mid < save)
                save = mid;
            r = mid-1;
        } else
            l = mid+1;
    }
    cout << save << endl;

    return 0;
}