#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); \
		cin.tie(NULL); \
		cout.tie(NULL); 

#define endl '\n'

using namespace std;

int X[105];
int B[10000];
int Blen;
int N, M;

int gcd(int a, int b)
{
	int n;
	while(b)
	{
		n = a%b;
		a = b;
		b = n;
	}

	return a;
}

int main(void)
{
	IO
	cin >> N;

	int stan;

	for(int i = 0; i < N; ++i)
		cin >> X[i];

	sort(X, X+N);

	stan = X[1]-X[0];

	for(int i = 2; i < N; ++i)
		stan = gcd(stan, X[i]-X[i-1]);

	for(int i = 1; i*i <= stan; ++i)
	{
		if(stan % i == 0)
		{
			B[Blen++] = i;
			if( i != stan/i)
				B[Blen++] = stan/i;
		}
	}

	sort(B, B+Blen);

	for(int i = 1; i < Blen; ++i)
		cout << B[i] << endl;

	return 0;
}
