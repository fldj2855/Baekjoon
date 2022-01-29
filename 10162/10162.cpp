#include<bits/stdc++.h>

int main(void)
{
    int A = 300, B = 60, C = 10;

    int time;
    scanf("%d", &time);

    if((time%B)%C)
    {
        printf("-1");
        return 0;   
    }
    printf("%d %d %d\n", time/A, (time%A)/B, (time%B)/C);
}