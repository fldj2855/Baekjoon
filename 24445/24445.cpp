#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M, R;

vector<vector<int>> E;
bool visited[100005];
int counter[100005];
int cnt = 1;

bool comp_des(int a, int b)
{
    return a > b;
}

void bfs(int R)
{
    visited[R] = true;
    counter[R] = cnt++;

    queue<int> Q;
    Q.push(R);

    while(!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();
        for(int v : E[tmp])
        {
            if(visited[v] == false)
            {
                visited[v] = true;
                Q.push(v);
                counter[v] = cnt++;
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

    for(int i = 1; i <= N; ++i)
        sort(E[i].begin(), E[i].end(), comp_des);
    
    bfs(R);

    for(int i = 1; i <= N; ++i)
        cout << counter[i] << endl;
}