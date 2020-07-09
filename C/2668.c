#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;
int count;
int D[105];
int memo[105];

int dfs(int start, int end)
{
	for(int i = 1; i <= n; ++i)
	{
		end = D[end];
		if(start == end)
			return (count++, memo[end]++);
	}
}

int main(void)
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &D[i]);
	for(int i = 1; i <= n; ++i)
		dfs(i, i);
	printf("%d\n", count);
	for (int i = 1; i <= n; ++i)
		if(memo[i])
			printf("%d\n", i);

	return 0;
}