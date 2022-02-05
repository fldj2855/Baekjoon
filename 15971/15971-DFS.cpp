#include<bits/stdc++.h>
#define endl '\n'
#define INT 1e9 + 7
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

using namespace std;

typedef pair<int, int> pii;

int N;
int Room1, Room2;

vector<vector<int>> adj;
vector<bool> visitmap;

map<pii, int> weight;

int dfs(int s, int e, long long *dist_sum, long long *max_weight)
{
    if(s == e)
        return 1;

    visitmap[s] = true;
    
    for(vector<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i)
    {
        if(visitmap[*i])
            continue;
  
        int w = weight.at({min(s, *i), max(s, *i)});
        *dist_sum += w;

        long long save_max = *max_weight; // save max value
        if(*max_weight < w)
            *max_weight = w;
        
        if(dfs(*i, e, dist_sum, max_weight)) // return1 -> found s-e route
            return 1;
        
        *max_weight = save_max; // roll-back
        *dist_sum -= w;
    }

    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int s, e, w;
    long long dist_sum = 0, max_weight = 0;
    cin >> N >> Room1 >> Room2;

    adj.resize(N+1);
    visitmap.resize(N+1);

    for(int i = 0; i < N-1; ++i)
    {
        cin >> s >> e >> w;
        
        adj[s].push_back(e);
        adj[e].push_back(s);
        weight.insert({pii(min(s, e), max(s, e)), w});
    }
    
    dfs(Room1, Room2, &dist_sum, &max_weight);

    cout << dist_sum - max_weight << endl;
    return 0;
}