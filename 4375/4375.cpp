#include<bits/stdc++.h>

int main(void)
{
    int n;
    while(scanf("%d", &n) != -1)
    {
        int l = 1;
        int i = 1;
        if(n == 1)
        {
            printf("1\n");
            continue;
        }
        while(l)
        {
            l=(l*10+1)%n;
            i++;
        }
        printf("%d\n", i);
    }
}