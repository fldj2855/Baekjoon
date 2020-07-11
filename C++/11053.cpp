#include<iostream>
#include<algorithm>
#define endl '\n'

int A[1005];
int dp[1005] = {1};

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int mc, save_max = 0;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> A[i];

	for(int i = 0; i < n; ++i)
	{
		mc = dp[0];
		for(int j = 0; j < i; ++j)
			if(A[i] > A[j])
				mc = (mc > dp[j]+1 ? mc : dp[j]+1);
		dp[i] = mc;
		if(save_max < mc)
			save_max = mc;
	}

	cout << save_max << endl;

	return 0;
}