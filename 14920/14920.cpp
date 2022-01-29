#include<bits/stdc++.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int dp[100005];

int fill(int idx)
{
    if(dp[idx] == 0)
    {
        if(idx%2 == 1) // odd
        {
            // only even/2
            dp[idx] = fill(idx*2);
            return dp[idx] + 1;
        }
        else // even
        {
            dp[idx] = MIN(fill((idx-1)/3), fill(idx*2));
        }
    }
    else
        return dp[idx];
}

void Init()
{
    dp[0] = -1;
    int cnt = 1;
    for(int i = 1; i < 100001; i*=2)
    {
        dp[i] = cnt++;
    }

    for(int i = 3; i < 100001; ++i)
    {
        fill(i);
    }
}

int main(void)
{
    
    return 0;
}