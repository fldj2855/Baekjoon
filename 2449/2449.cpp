#include<bits/stdc++.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define endl '\n'

using namespace std;

int dp[202][202];
int L[202];
int N, K;

int solve(int s, int e)
{
    if(s == e)
        return 0;
    
    if(dp[s][e] != -1)
        return dp[s][e];
    
    dp[s][e] = 987654321;
    for(int i = s; i < e; ++i)
        dp[s][e] = MIN(dp[s][e], solve(s,i)+solve(i+1,e) + (L[s]!=L[i+1]));
    
    return dp[s][e];
}

int main(void)
{
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));
    
    for(int i = 1; i <= N; ++i)
        cin >> L[i];

    cout << solve(1, N) << endl;

}