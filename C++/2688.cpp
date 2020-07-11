#include<iostream>

using namespace std;

long long unsigned int dp[70][10]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
long long unsigned int sum[70] = {10};
int main(void)
{
	long long unsigned int S = 0;

	for(int i = 1; i <= 64; ++i)
	{
		S = 0;
		for(int j = 0; j < 10; ++j)
		{
			for(int z = 0; z <= j; ++z)
				dp[i][j] += dp[i-1][z];
			S += dp[i][j];
		}
		sum[i] = S;
	}

	int n;
	cin >> n;
	while(n--)
	{
		int tmp;
		cin >> tmp;
		cout << sum[tmp-1] << endl;
	}
	return 0;
}