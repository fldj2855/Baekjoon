#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct work{
	int day;
	int price;
}W;

int N;
W P[20];
int memo[20];

void dp(int idx, int price)
{
	if(memo[idx] >= price)
		return;
	if(memo[idx] < price)
		memo[idx] = price;

	for(int i = idx+P[idx].day; i <= N; ++i)
	{
		if(i + P[i].day - 1 <= N)
			dp(i, price+P[i].price);
	}
}

int main(void)
{
	
	int d, p;
	int max = 0;
	int tmp;

	scanf("%d", &N);

	for(int i = 1; i <= N; ++i)
		scanf("%d %d", &P[i].day, &P[i].price);
	
	for(int i = 1; i <= N; ++i)
	{
		if(i + P[i].day -1 <= N)
			dp(i, P[i].price);
	}

	for(int i = 1; i <= N; ++i)
	{
		if(max < memo[i])
			max = memo[i];
	}

	printf("%d\n", max);

	return 0;
}