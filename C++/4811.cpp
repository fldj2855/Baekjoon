#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

unsigned long long dp[35][35];

void init()
{
	for(int i = 0; i <= 30; ++i)
		dp[i][0] = 1;

	for(int i = 1; i <= 30; ++i)
	{
		for(int j = 0; j <= 31-i; ++j)
		{
			if(j == 0)
				dp[j][i] += dp[j+1][i-1];
			else
				dp[j][i] += dp[j+1][i-1] + dp[j-1][i];
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	
	int n;
	while(1)
	{
		cin >> n;
		if(n)
			cout << dp[0][n] << endl;
		else
			break;
	}

	return 0;
}