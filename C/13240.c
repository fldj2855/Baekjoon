#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			if((i^j)&1) printf(".");
			else printf("*");
		}
		printf("\n");
	}

	return 0;
}