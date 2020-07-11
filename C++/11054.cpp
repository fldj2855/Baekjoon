#include<iostream>
#include<algorithm>
#define endl '\n'
#define max(A, B) (A > B ? A : B)

using namespace std;

int A[1005];
int dp[1005];
int dp2[1005];
int main(void)
{
	int n;
	int mc,mc2;
	int save_max = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> A[i];

	dp[0] = dp2[n-1] = 1;

	for(int i = 0; i < n; ++i)
	{
		mc = dp[0];
		for(int j = 0; j < i; ++j)
			if(A[i] > A[j])
				mc = max(mc, dp[j]+1);

		dp[i] = mc;
	}

	for(int i = n-1; i >= 0; --i)
	{
		mc2 = dp2[n-1];
		for(int j = n-1; j >= i; --j)
			if(A[i] > A[j])
				mc2 = max(mc2, dp2[j]+1);
		dp2[i] = mc2;
	}

	for(int i = 0; i < n; ++i)
		if(dp[i]+dp2[i]-1 > save_max)
			save_max = dp[i] + dp2[i] -1;

	cout << save_max << endl;

	return 0;
}