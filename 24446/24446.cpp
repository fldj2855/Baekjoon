#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M, R;

vector<vector<int>> E;
bool visited[100005];
int Level[100005];
int cnt = 1;

void bfs(int R)
{
    visited[R] = true;
    Level[R] = cnt++;

    deque<int> DQ;
    DQ.push_back(R);

    while(!DQ.empty())
    {
        int tmp = DQ.front();
        DQ.pop_front();
        for(int v : E[tmp])
        {
            if(visited[v] == false)
            {
                visited[v] = true;
                DQ.push_back(v);
                Level[v] = Level[tmp]+1;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a, b;

    cin >> N >> M >> R;

    E.resize(N+1);

    for(int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    bfs(R);

    for(int i = 1; i <= N; ++i)
    {
        if(Level[i])
            cout << Level[i] - 1 << endl;
        else
            cout << "-1" << endl;
    }
}