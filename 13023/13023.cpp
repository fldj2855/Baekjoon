#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M;

vector<vector<int>> adj;

bool visited[2001];
void dfs(int s, int cnt)
{
    visited[s] = 1;
    if(cnt == 5)
    {
        cout << 1 << endl;
        exit(0);
    }

    for(vector<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i)
    {
        if(visited[*i] == 0)
        {
            dfs(*i, cnt+1);
        }
    }

    visited[s] = 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M;

    adj.resize(N);

    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < N; ++i)
        dfs(i, 1);

    cout << 0 << endl;
    return 0;
}