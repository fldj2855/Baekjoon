#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef struct Data
{
	int prime;
	int count;	
}Data;

int E[10005];
bool visited[10005];

void init()
{
	E[1] = 1;
	for(int i = 2; i*i <= 10000; ++i)
	{
		for(int j = i*i; j <= 10000; j+=i)
		{
			E[j] = 1;
		}
	}
}

int BFS(int start, int end)
{
	Data p;
	queue<Data> q;
	q.push({start, 0});

	while(!q.empty())
	{
		p = q.front();
		q.pop();

		if(p.prime == end)
			return p.count;

		for(int i = 1; i <= 9; ++i)
		{
			int tmp = i*1000+p.prime%1000;
			if(E[tmp] == 0 && visited[tmp] == 0)
			{
				visited[tmp] = 1;
				q.push({tmp, p.count+1});
			}
		}

		for(int i = 0; i <= 9; ++i)
		{
			int tmp = (p.prime/1000)*1000 + i*100 + p.prime%100;
			if(E[tmp] == 0 && visited[tmp] == 0)
			{
				visited[tmp] = 1;
				q.push({tmp, p.count+1});
			}

			tmp = (p.prime/100)*100 + i*10 + p.prime%10;
			if(E[tmp] == 0 && visited[tmp] == 0)
			{
				visited[tmp] = 1;
				q.push({tmp, p.count+1});
			}

			tmp = (p.prime/10)*10 + i;
			if(E[tmp] == 0 && visited[tmp] == 0)
			{
				visited[tmp] = 1;
				q.push({tmp, p.count+1});
			}
		}

	}

	return -1;
}

int main(void)
{
	init();

	int t;
	scanf("%d", &t);

	while(t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", BFS(a, b));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}