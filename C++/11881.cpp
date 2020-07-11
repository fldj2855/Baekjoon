#include<bits/stdc++.h>

#define endl '\n'
#define mod 1000000007

using namespace std;

unsigned long long COUNT[100005];
unsigned long long DP[1000005];
unsigned long long ans;

int main(void)
{
	int n, tmp;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> tmp;
		COUNT[tmp]++;
	}

	for(int i = 1; i <= 100000; ++i)
		DP[i] = (DP[i-1] + i*COUNT[i]);

	for(int i = 1; i <= 100000; ++i)
		ans = (ans+(DP[i-1]*(DP[i]-DP[i-1])%mod*(DP[100000]-DP[i])%mod)%mod)%mod;

	cout << ans << endl;
	
	return 0;
}