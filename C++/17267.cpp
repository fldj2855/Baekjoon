#include<bits/stdc++.h>
#define endl '\n';

using namespace std;

typedef struct Point
{
	int x, y;
	int L, R;	
}P;

bool visited[1005][1005];
int N, M;
int L, R;
int y, x;

int BFS()
{
	int res = 0;
	int i;

	P p;
	
	queue< P > Q;
	Q.push({x, y, L, R});

	visited[y][x] = 1;
	res+=1;

	while(!Q.empty())
	{
		p = Q.front(); Q.pop();

		//up
		i = 1;
		while(0 <= p.y-i && visited[p.y-i][p.x] == 0)
		{
			Q.push({p.x, p.y-i, p.L, p.R});
			visited[p.y-i][p.x] = 1;
			res+=1;
			i+=1;
		}

		//down
		i = 1;
		while(p.y+i < N && visited[p.y+i][p.x] == 0)
		{
			Q.push({p.x, p.y+i, p.L, p.R});
			visited[p.y+i][p.x] = 1;
			res += 1;
			i+=1;
		}

		//left
		if(0 < p.x && visited[p.y][p.x-1] == 0 && p.L)
		{
			Q.push({p.x-1, p.y ,p.L-1, p.R});
			visited[p.y][p.x-1] = 1;
			res+=1;
		}

		//right
		if(p.x < M-1 && visited[p.y][p.x+1] == 0 && p.R)
		{
			Q.push({p.x+1, p.y, p.L, p.R-1});
			visited[p.y][p.x+1] = 1;
			res+=1;
		}
	}

	return res;
}

int main(void)
{
	int tmp;
	scanf("%d %d", &N, &M);
	scanf("%d %d", &L, &R);

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
		{
			scanf("%1d", &tmp);
			if(tmp == 2)
			{
				y = i; x = j;
				visited[i][j] = 0;
			}
			else
				visited[i][j] = tmp;
		}

	cout << BFS() << endl;

	return 0;
}