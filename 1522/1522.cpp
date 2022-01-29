#include<bits/stdc++.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int min_cnt(char *str, int idx, int b_cnt, int len)
{
    int a_cnt = 0;
    for(int i = idx; i < idx+b_cnt; ++i)
    {
        if(str[i%len] == 'a')
            a_cnt++;
    }

    return a_cnt;
}

int main(void)
{
    char str[1001];
    scanf("%s", str);
    
    int len = strlen(str);
    int b_cnt = 0;
    int ans = 9999;

    for(int i = 0; i < len; ++i)
    {
        if(str[i] == 'b')
            b_cnt ++;
    }

    for(int i = 0; i < len; ++i)
    {
        ans = MIN(ans, min_cnt(str, i, b_cnt, len));
    }

    printf("%d\n", ans);
}

