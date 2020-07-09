#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int board[105][105];

int main(void)
{
	int x1, y1, x2, y2;
	int count = 0;

	for(int i = 0; i < 4; ++i)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for(int j = x1; j < x2; ++j)
		{
			for(int z = y1; z < y2; ++z)
			{
				board[j][z] = 1;
			}
		}
	}

	for(int i = 0; i < 100; ++i)
		for(int j = 0; j < 100; ++j)
			if(board[i][j])
				count++;

	printf("%d\n", count);

	return 0;
}