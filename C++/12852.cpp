#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef struct Data
{
	int value;
	int count;
}Data;
int dp[1000005][2];

void BFS(int N)
{
	Data p;
	queue<Data> Q;
	Q.push({1, 0});

	while(!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if(p.value == N)
			return;

		if(p.value+1 <= N && dp[p.value+1][0] == 0)
		{
			dp[p.value+1][0] = p.value;
			dp[p.value+1][1] = p.count+1;
			Q.push({p.value+1, p.count+1});
		}
		if(p.value*2 <= N && dp[p.value*2][0] == 0)
		{
			dp[p.value*2][0] = p.value;
			dp[p.value*2][1] = p.count+1;
			Q.push({p.value*2, p.count+1});
		}
		if(p.value*3 <= N && dp[p.value*3][0] == 0)
		{
			dp[p.value*3][0] = p.value;
			dp[p.value*3][1] = p.count+1;
			Q.push({p.value*3, p.count+1});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0][0] = 0;
	dp[1][0] = 0;

	int N, i;
	cin >> N;

	BFS(N);
	
	cout << dp[N][1] << endl;
	for(i = N; i != 0; i = dp[i][0])
		cout << i << ' ';
	// cout << 1;
	return 0;
}