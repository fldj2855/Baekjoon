#include<bits/stdc++.h>

#define endl '\n'
using namespace std;

int dp[10][10];
int X[10][10];
int ans[10];

int main(void)
{
	cout.tie(0);
	cin.tie(0);
	int t;
	int N, M;
	int flag;
	char ch;
	scanf("%d", &t);

	while(t--)
	{	
		scanf("%d %d", &N, &M);
		getchar();
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < M; ++j)
			{
				scanf("%c", &ch);
				if(ch == '.')
					X[i][j]+=1;
			}
			getchar();
		}

		// Array X
		// x --> 0
		// . --> 1
		for(int i = 0; i < M; ++i)
		{
			dp[0][i] = X[0][i];
			dp[1][i] = X[1][i] + X[0][i];
		}

		for(int i = 2; i < N; ++i)
		{
			for(int j = 0; j < M; ++j)
			{
				
			}
		}

		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < M; ++j)
			{
				cout << dp[i][j] << ' ';
			}
			cout << endl;
		}

		ans[0] = dp[N-1][0];
		ans[1] = dp[N-1][1];
		ans[2] = dp[N-1][0] + dp[N-1][2];

		for(int i = 3; i < M; ++i)
			ans[i] = max(ans[i-2] + dp[N-1][i], ans[i-3] + dp[N-1][i]);

		cout << "[*] ans" << endl;
		for(int i = 0; i < M; ++i)
			cout << ans[i] << ' ';
		cout << endl;
		cout << "[*] ans ==> " << max(ans[M-1], ans[M-2]) << endl;
		memset(dp, 0, sizeof(dp));
		memset(X, 0, sizeof(X));
	}

	return 0;
}