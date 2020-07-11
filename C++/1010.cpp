#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

unsigned int dp[35][35];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0][0] = 1;
	for(int i = 0; i < 30; ++i)
		dp[i][0] = dp[i][i] = 1;
	
	for(int i = 2; i < 30; ++i)
	{
		for(int j = 1; j < i; ++j)
		{
			unsigned int tmp = 0;
			for(int z = 0; z < i; ++z)
				tmp += dp[z][j-1];
			dp[i][j] = tmp;

		}
	}

	int t;
	int v1, v2;
	cin >> t;
	while(t--)
	{
		cin >> v1 >> v2;
		if(v2 > v1)
			swap(v1, v2);
		cout << dp[v1][v2] << endl;
	}

	return 0;
}