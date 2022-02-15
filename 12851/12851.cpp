#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int visited[200005];
int minimum = 0;

void bfs(int N, int K)
{
    queue<int> Q;
    visited[N] = 1;

    Q.push(N);

    minimum = 0;
    while(!minimum && !Q.empty())
    {
        int depth = Q.size();
        for(int i = 0; i < depth; ++i)
        {
            int n = Q.front();
            Q.pop();

            // cout << n << endl;
            minimum += (n==K);

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
                visited[2*n] = visited[n] + 1;
                Q.push(2*n);
            }
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
        cout << 1 << endl;
        return 0;
    }
    bfs(n, k);
    cout << visited[k] - 1 << endl;
    cout << minimum << endl;
}