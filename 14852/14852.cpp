#include<bits/stdc++.h>
#define endl '\n'
#define MOD 1000000007

using namespace std;

long long dp[2][4] = {
    {0, 2, 7},
    {0, 0, 1}
};
long long dl=3;
long long N;

int main(void)
{
    cin >> N;
    if(N < 2)
    {
        cout << dp[0][N] << endl;
        return 0;
    }
    N -= 2;
    while(N--)
    {
        dp[1][dl] = (dp[0][(dl+1)%4] + dp[1][(dl+3)%4])%MOD;
        dp[0][dl] = (2 * dp[0][(dl+3)%4] + 3 * dp[0][(dl+2)%4] + 2 * dp[1][dl])%MOD;
        dl=(dl+1)%4;
    }

    cout << dp[0][(dl+3)%4] << endl;
}