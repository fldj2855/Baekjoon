#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

double N, L;

void go(long long start, int len)
{
	for(int i = 0; i < len; ++i)
		cout << start+i << ' ';
}

int main(void)
{
	cin >> N >> L;
	double i;

	for(long long l = L;l <= 100; ++l)
	{
		i = N/(double)l - (l-1)/2.;
		if(i < 0)
			continue;
		
		if(i == (long long)i)
		{
			go((long long)i, l);
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}