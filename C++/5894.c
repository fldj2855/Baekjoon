#include<stdio.h>

#define right 1
#define left 2
#define up 4
#define down 8

#define stan_x 1000
#define stan_y 1000

#define MAX 0
#define MIN 1

int X[2005][2005];
int S[2005][2];
int G[2005][2];

int N;
int cnt;

void BT(int y, int x, int come, int k);
void search(int y, int x, int mode, int k);

int main(void)
{
	int x, y, i;

	for(int i = 0; i <= 2000; ++i)
	{
		S[i][MAX] = -1;
		S[i][MIN] = 2001;
		G[i][MAX] = -1;
		G[i][MIN] = 2001;
	}

	scanf("%d", &N);
	
	for(int i = 0; i < N; ++i)
	{
		scanf("%d %d", &x, &y);
		X[y+stan_y][x+stan_x] = 1;

		if(S[x+stan_x][MAX] < y+stan_y)
			S[x+stan_x][MAX] = y+stan_y;
		if(y+stan_y < S[x+stan_x][MIN])
			S[x+stan_x][MIN] = y+stan_y;

		if(G[y+stan_y][MAX] < x + stan_x)
			G[y+stan_y][MAX] = x+stan_x;
		if(x+stan_x < G[y+stan_y][MIN])
			G[y+stan_y][MIN] = x+stan_x;
	}

	// printf("%d %d\n", S[1002][0], S[1002][1]);
	for(i = stan_x+1; i <= G[stan_y][MAX]; ++i)
		search(stan_y, i, right, 1);
	
	for(i = G[stan_y][MIN]; i < stan_x; ++i)
		search(stan_y, i, left, 1);
	
	for(i = stan_y+1; i <= S[stan_x][MAX]; ++i)
		search(i, stan_x, up, 1);

	for(i = S[stan_x][MIN]; i < stan_y; ++i)
		search(i, stan_x, down, 1);

	printf("%d", cnt);

	return 0;
}

void BT(int y, int x, int come, int k)
{
	int i;
	
	// printf("(%d, %d) %d %d\n", x, y, come, k);

	if(k == N)
	{
		// printf("k == N!! (%d, %d) %d %d\n", x, y, come, k);
		if(come == right)
		{
			if(x == stan_x) cnt++;
			else if(x > stan_x && y == stan_y) cnt++;
		}
		if(come == left)
		{
			if(x == stan_x) cnt++;
			else if(x < stan_x && y == stan_y) cnt++;
		}
		if(come == up)
		{
			if(x == stan_x && y > stan_y) cnt++;
			else if(y == stan_y) cnt++;
		}
		if(come == down)
		{
			if(x == stan_x && y < stan_y) cnt++;
			else if(y == stan_y) cnt++;
		}
		return;
	}

	for(i = x+1;(come ^ right) && i <= G[y][0]; ++i)
		search(y, i, right, k+1);
	
	for(i = G[y][1];(come ^ left) &&  i < x; ++i)
		search(y, i, left, k+1);

	for(i = y+1;(come ^ up) && i <= S[x][0]; ++i)
		search(i, x, up, k+1);

	for(i = S[x][1];(come ^ down) && i < y; ++i)
		search(i, x, down, k+1);

}

void search(int y, int x, int mode, int k)
{
	if(X[y][x])
	{
		X[y][x] = 0;
		BT(y, x, mode, k);
		X[y][x] = 1;
	}
}