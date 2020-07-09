#include<stdio.h>
#include<stdlib.h>

/*

(N-1)%3 == 0 -> 초기상태 : 전부 O
(N-1)%3 == 1 -> 폭탄 구역만 보여줌 
(N-1)%3 == 2 -> 터지고난 직후
*/

char board[201][201];
char board2[201][201];
int R, C, N;

int check(int y, int x)
{
	int X[] = {1, -1, 0, 0};
	int Y[] = {0, 0, 1, -1};

	if(board[y][x] == 'O')
		return 1;

	for(int i = 0; i < 4; ++i)
	{
		if((0 <= y+Y[i] && y+Y[i] < R) && (0 <= x+X[i] && x+X[i] < C))
			if(board[y+Y[i]][x+X[i]] == 'O')
				return 1;
	}

	return 0;
}

int main(void)
{
	scanf("%d %d %d", &R, &C, &N);
	N = (N-1)%3;

	for(int i = 0; i < R; ++i)
		scanf("%s", board[i]);
	
	if(N == 0)
	{
		for(int i = 0; i < R; ++i)
		{
			for(int j = 0; j < C; ++j)
			{
				printf("%c", 'O');
			}
			printf("\n");
		}
		return 0;
	}
	if(N == 1)
	{
		for(int i = 0; i < R; ++i)
			printf("%s\n", board[i]);
		return 0;
	}
	else
	{
		for(int i = 0; i < R; ++i)
		{
			for(int j = 0; j < C; ++j)
			{
				if(check(i, j))
					board2[i][j] = '.';
				else
					board2[i][j] = 'O';
			}
		}
	}

	for(int i = 0; i < R; ++i)
		printf("%s\n", board2[i]);
	return 0;
}