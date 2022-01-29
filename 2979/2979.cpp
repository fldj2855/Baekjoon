#include<bits/stdc++.h>

int main(void)
{
    int A, B, C;
    int Time[105] = {0};
    scanf("%d %d %d", &A, &B, &C);

    int s, e;
    for(int i = 0; i < 3; ++i)
    {
        scanf("%d %d", &s, &e);
        for(int j = s; j < e; ++j)
            Time[j]++;
    }
    
    int ans = 0;
    for(int i = 1; i <= 100; ++i)
    {
        if(Time[i] == 1)
            ans += A;
        else if(Time[i] == 2)
            ans += B*2;
        else if(Time[i] == 3)
            ans += C*3;
    }

    printf("%d\n", ans);
}