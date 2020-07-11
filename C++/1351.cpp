#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

map<long long, long long> memo;

long long N, P, Q;

long long S(long long n)
{
	if(memo[n])
		return memo[n];
	else
		return memo[n] = S(n/P) + S(n/Q);
}

int main(void)
{
	cin >> N >> P >> Q;
	memo[0LL] = 1LL;

	cout << S(N) << endl;
	return 0;
}