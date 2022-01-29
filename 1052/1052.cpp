#include<bits/stdc++.h>

int bit_count(size_t num)
{
    int ret = 0;
    while(num)
    {
        if(num & 1)
            ret += 1;
        num /= 2;
    }

    return ret;
}
int main(void)
{
    size_t N, K, cnt = 0;
    size_t bitmask = 0;

    scanf("%lu %lu", &N, &K);

    while(bit_count(N) > K)
    {
        // printf("%d\n", N&(-N));
        cnt += N&(-N);
        N += N&(-N);
    }

    printf("%d\n",  cnt);

}