#include<iostream>
#include<algorithm>
#define endl '\n'
#define mod 1000000009

using namespace std;

int dp1[100005] = {0, 1, 0, 1};
int dp2[100005] = {0, 0, 1, 1};
int dp3[100005] = {0, 0, 0, 1};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t;
	cin >> n;

	for(int i = 4; i <= 100000; ++i)
	{
		dp1[i] = (dp2[i-1] + dp3[i-1])%mod;
		dp2[i] = (dp1[i-2] + dp3[i-2])%mod;
		dp3[i] = (dp1[i-3] + dp2[i-3])%mod;
	}

	while(n--)
	{
		cin >> t;
		cout << ((long)dp1[t]+(long)dp2[t]+(long)dp3[t])%mod << endl;
	}

	return 0;
}