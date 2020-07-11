#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

long long P(long long x, long long y, long long mod)
{
	if(y == 0)
		return 1;
	if(y%2 == 1)
		return (x*P(x, y-1, mod))%mod;
	return P((x*x)%mod, y/2, mod) % mod;
}

int main(void)
{
	int t;
	long long n;
	long long M = 1000000007;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << P(2, n-2, M) << endl;;
	}

	return 0;
}