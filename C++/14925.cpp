#include<bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int M, N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	int cnt = 0;

	cin >> M >> N;

	for(i = 0; i < M; ++i){
		for(j = 0; j < N; ++j){
			cin >> dp[i][j];
			if(dp[i][j] != 0)
				dp[i][j] = -1;
		}
	}

	for(i = 0; i < M; ++i){
		for(j = 0; j < N; ++j){
			if(dp[i][j] != -1)
			{
				if(i == 0 || j == 0)
					dp[i][j] = 1;
				else if(i > 0 && j > 0)
				{
					int k = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
					if(k == -1)
						dp[i][j] = 1;
					else
						dp[i][j] += k + 1;
				}

				if(cnt < dp[i][j])
					cnt = dp[i][j];
			}
		}
	}

	cout << cnt << endl;

	return 0;
}