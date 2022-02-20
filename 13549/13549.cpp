#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int visited[200005];

void bfs(int N, int K)
{
    queue<int> Q;
    visited[N] = 1;

    Q.push(N);

    while(!Q.empty())
    {
        int n = Q.front();
        Q.pop();

        if(0 <= n-1 && (visited[n-1] == 0 || visited[n-1] > visited[n]))
        {
            visited[n-1] = visited[n] + 1;
            Q.push(n-1);
        }
        
        if(n+1 <= 200000 && (visited[n+1] == 0 || visited[n+1] > visited[n]))
        {
            visited[n+1] = visited[n] + 1;
            Q.push(n+1);
        }

        if(2*n <= 200000 && (visited[2*n] == 0 || visited[2*n] > visited[n]))
        {
            // 0 second
            visited[2*n] = visited[n];
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
        return 0;
    }
    bfs(n, k);
    cout << visited[k] - 1 << endl;
}