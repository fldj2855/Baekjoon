#include<stdio.h>
#include<string.h>

int X[1005][1005];
int N, M, V;

void BFS(int s, int t)
{
	
	for(int i = 0; i < N; ++i)
	{
		if(X[s][i] == 1)
		{
			printf("%d ", i);
		}
	}
}

void DFS()
{

}

int main(void)
{
	int p1, p2;

	scanf("%d %d %d", &N, &M, &V);

	for(int i = 0; i < N; ++i)
	{
		scanf("%d %d", &p1, &p2);
		p1--;
		p2--;
		X[p1][p2] = 1;
		X[p2][p1] = 1;
	}

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			printf("%d ", X[i][j]);
		}
		printf("\n");
	}

	// DFS(V);
	// BFS(V);

	return 0;
}