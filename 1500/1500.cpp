#include<bits/stdc++.h>

int main(void)
{
    int S, K;
    int elem[20] = {0};
    size_t ans = 1;

    scanf("%d %d", &S, &K);

    for(int i = 0; i < K; ++i)
        elem[i] = S/K;

    for(int i = 0; i < S%K; ++i)
        elem[i]++;

    for(int i = 0; i < K; ++i)
        ans *= elem[i];
    printf("%lu\n", ans);
    
}