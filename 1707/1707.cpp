#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int T;
int V, E;

bool visited[2][20001];
vector<vector<int>> adj;
void dfs(int idx, bool from_color, int *flag)
{   
    visited[0][idx] = true;
    visited[1][idx] = from_color;

    for(vector<int>::iterator to = adj[idx].begin(); !*flag && to != adj[idx].end(); ++to)
    {
        if(!visited[0][*to])
        {
            dfs(*to, !from_color, flag);
        }
        else if(visited[0][*to] && visited[1][*to] == from_color)
        {
            // fuck you
            *flag = 1;
            return;
        }
    }

    return;
}
int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int flag;
    cin >> T;

    while(T--)
    {
        cin >> V >> E;

        adj.resize(V+1);
        for(int i = 0; i < E; ++i)
        {
            int tmpV, tmpV2;
            cin >> tmpV >> tmpV2;
            adj[tmpV].push_back(tmpV2);
            adj[tmpV2].push_back(tmpV);
        }

        memset(visited, 0, sizeof(visited));
        flag = 0;
        for(int i = 1; !flag && i <= V; ++i)
            if(!visited[0][i])
                dfs(i, 0, &flag);
        adj.clear();
        cout << (flag?"NO":"YES") << endl;
    }
}