#include<iostream>
#include<algorithm>
#include<map>
#include<utility>
#include<vector>
#define endl '\n'
#define MAX(a, b) (a > b ? a : b)

/*

연속 3개 X 
안마실 수도 있음!

n-5		n-4		n-3		n-2		n-1		n
						dp[n-2]			s[n]
				dp[n-3]			s[n-1]	s[n]
		dp[n-4]					s[n-1]	s[n]
		dp[n-4]			s[n-2]			s[n]	


*/

using namespace std;

int dp[10005];
int wine[10005];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
		cin >> wine[i];

	dp[1] = wine[1];
	dp[2] = wine[1]+wine[2];
	dp[3] = MAX(wine[1] + wine[3], wine[2]+wine[3]);
	dp[4] = MAX(dp[2] + wine[4], dp[1] + wine[3] + wine[4]);

	for(int i = 5; i <= n; ++i)
		dp[i] = MAX(MAX(dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i]),
		 MAX(dp[i-4] + wine[i-2] + wine[i], dp[i-4] + wine[i-1] + wine[i] ));

	// for(int i = 1; i <= n; ++i)
	// 	cout << dp[i] << ' ';
	// cout << endl;

	cout << MAX(dp[n-1],dp[n]) << endl;

	return 0;
}