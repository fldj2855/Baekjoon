#include<stdio.h>

void build_min_heap(int *, int);
void heap_sort(int *, int);
void heapify(int *, int, int);

int A[500005];
int N, K;
int hook = 1;
int exchange_cnt = 0;

int main(void)
{
    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);

    heap_sort(A, N);

    if(exchange_cnt < K)
        printf("-1\n");
    
}

void build_min_heap(int *A, int n)
{
    for(int i = n/2; i>0; --i)
    {
        heapify(A, i, n);
    }
}
void heap_sort(int *A, int n)
{

    build_min_heap(A, n);
    for(int i = n; i>=2; --i)
    {
        exchange_cnt++;
        if(exchange_cnt == K)
            printf("%d %d\n", A[1], A[i]);
        A[1]^=A[i]^=A[1]^=A[i];
        heapify(A, 1, i-1);
    }
}

void heapify(int *A, int k, int n)
{
    int left = 2*k, right = 2*k+1;
    int smaller;

    if(right <= n)
    {
        if(A[left] < A[right])
            smaller = left;
        else
            smaller = right;
    }
    else if(left <= n)
        smaller = left;
    else
        return;

    if(A[smaller] < A[k])
    {
        exchange_cnt++;
        if(exchange_cnt == K)
            printf("%d %d\n", A[smaller], A[k]);
        A[smaller]^=A[k]^=A[smaller]^=A[k];
        

        heapify(A, smaller, n);
    }
}