#include<iostream>

#define MOD 9901

using namespace std;

int dp[100005] = {1, 3};

int main(void)
{
	int n;
	cin >> n;

	for(int i = 2; i <= n; ++i)
		dp[i] = (dp[i-2] + dp[i-1]*2)%MOD;
	
	cout << dp[n] << endl;

	return 0;
}