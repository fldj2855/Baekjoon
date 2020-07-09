#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int X[10005];
int N, M;

int main(void)
{
	int start, end;
	int cnt = 0;
	int sum = 0;

	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; ++i)
		scanf("%d", X+i);

	start = end = 0;
	for(int i = 0; i < N; ++i)
	{
		while(sum < M && end < N)
			sum += X[end++];

		if(sum == M)	cnt++;

		sum -= X[start++];
	}

	printf("%d", cnt);
	return 0;
}