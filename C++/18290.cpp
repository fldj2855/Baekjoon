#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

bool c[15];

int X[15][15];

int N, M, K;
int ans=-987654321;

void trace(int y, int sum, int k)
{
	if(k == 0)
	{
		if(ans < sum)
			ans = sum;
		return;
	}

	for(int i = y; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if(c[j])
				continue;
			c[j] = 1;
			trace(i+1, sum + X[i][j], k-1);
			c[j] = 0;
		}
	}
}

int main(void)
{
	cin >> N >> M >> K;

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			cin >> X[i][j];
		}
	}

	trace(0, 0, K);

	cout << ans << endl;

	return 0;
}