#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M;
unsigned int dp[1002][1002];
bool bridge[1002][1002];
int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            cin >> bridge[i][j];
        }
    }

    for(int i = 1; i <= M; ++i)
        dp[N][i] = bridge[N][i];
    
    for(int i = N-1; i >= 1; --i)
    {
        for(int j = 1; j <= M; ++j)
        {
            if(bridge[i][j])
                dp[i][j] = (dp[i+1][j-1] + dp[i+1][j] + dp[i+1][j+1])%1000000007;
        }
    }

    long long ans = 0;
    for(int i = 1; i <= M; ++i)
        ans = (ans + dp[1][i])%1000000007;
        
    cout << ans << endl;
    return 0;
}