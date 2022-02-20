#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int visited[200005][2];

void ans(int k)
{
    if(k == -1)
        return;
    else
        ans(visited[k][1]);
    cout << k << " ";
}

void bfs(int N, int K)
{
    queue<int> Q;
    visited[N][0] = 1;
    visited[N][1] = -1;

    Q.push(N);

    while(!Q.empty())
    {
        int n = Q.front();
        Q.pop();

        if(0 <= n-1 && (visited[n-1][0] == 0 || visited[n-1][0] > visited[n][0]))
        {
            visited[n-1][0] = visited[n][0] + 1;
            visited[n-1][1] = n;
            Q.push(n-1);
        }
        
        if(n+1 <= 200000 && (visited[n+1][0] == 0 || visited[n+1][0] > visited[n][0]))
        {
            visited[n+1][0] = visited[n][0] + 1;
            visited[n+1][1] = n;
            Q.push(n+1);
        }

        if(2*n <= 200000 && (visited[2*n][0] == 0 || visited[2*n][0] > visited[n][0]))
        {
            // 0 second
            visited[2*n][0] = visited[n][0] + 1;
            visited[2*n][1] = n;
            Q.push(2*n);
        }
    }
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    if(k < n)
    {
        cout << n-k << endl;
        for(int i = n; i >= k; --i)
            cout << i << " ";
        return 0;
    }
    bfs(n, k);
    cout << visited[k][0] - 1 << endl;
    ans(k);
}