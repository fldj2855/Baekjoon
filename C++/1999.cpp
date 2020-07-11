#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;
int dp[255][255];
int mt[255][255];
int N, B, K;

int R(int s, int e)
{
	int M, m;
	M = mt[s][e];
	m = mt[s][e];

	for(int i = s; i < s+B; ++i)
	{
		for(int j = e; j < e+B; ++j)
		{
			if(M < mt[i][j])
				M = mt[i][j];
			if(mt[i][j] < m)
				m = mt[i][j];
		}
	}

	return M-m;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> N >> B >> K;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cin >> mt[i][j];

	for(int i = 0; i < N-B+1; ++i)
		for(int j = 0; j < N-B+1; ++j)
			dp[i][j] = R(i, j);

	for(int i = 0; i < K; ++i)
	{
		cin >> x >> y;
		cout << dp[x-1][y-1] << endl;
	}

	return 0;
}