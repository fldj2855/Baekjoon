#include<stdio.h>
 
int fct(int x) {
    int sum = 0;
 
    while (x) {
        sum += x % 10;
        x /= 10;
    }
 
    return sum;
}
 
int main(void) {
 
    int n;
    scanf("%d", &n);
    int t=1;
    for (int i = 1; i <= n; ++i) {
        if (i + fct(i) == n) {
            printf("%d", i);
            t = 0;
            break;
        }
    }
 
    if (t)    printf("0");
    return 0;
}