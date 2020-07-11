#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int dp[100005];

int main(void)
{
	int N, K, W, V;
	int save_mc = 0;

	cin >> N >> K;

	for(int i = 0; i < N; ++i)
	{
		cin >> W >> V;
		for(int j = K-W; j >= 0; --j)
		{
			if(dp[j+W])
			{
				if(dp[j+W] < dp[j] + V)
					dp[j+W] = dp[j]+V;
			}
			else
				dp[j+W] = V;
		}
	}

	for(int i = 0; i <= K; ++i)
	{
		// cout << dp[i] << ' ';
		if(dp[i] > save_mc)
			save_mc = dp[i];
	}

	// cout << endl;
	cout << save_mc << endl;

	return 0;
}