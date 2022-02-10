#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M, R;
vector<vector<int>> E;
bool visited[100005];
int Level[100005];
int Time[100005];
int t = 1;
long long ans = 0;

void bfs(int R)
{
    for(int i = 1; i <= N; ++i)
        Level[i] = -1;
    
    visited[R] = true;
    Level[R] = 0;
    Time[R] = t++;

    queue<int> DQ;
    DQ.push(R);

    while(!DQ.empty())
    {
        int tmp = DQ.front();
        DQ.pop();
        for(int v : E[tmp])
        {
            if(visited[v] == false)
            {
                visited[v] = true;
                DQ.push(v);
                Level[v] = Level[tmp]+1;
                Time[v] = t++;                    
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a, b;

    cin >> N >> M >> R;

    E.resize(N+1);

    for(int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    for(int i = 1; i <= N; ++i)
        sort(E[i].begin(), E[i].end());
    
    bfs(R);

    for(int i = 1; i <= N; ++i)
    {
        // cout << Time[i] << " " << Level[i] << endl;
        ans += (long long)Time[i] * Level[i];
    }
        
    cout << ans << endl;
}