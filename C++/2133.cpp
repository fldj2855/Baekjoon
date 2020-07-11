#include<bits/stdc++.h>

using namespace std;

unsigned long long int DP[35];

int main(void)
{
	int n;
	DP[2] = 3;

	for(int i = 4; i <= 30; i+=2)
	{
		for(int j = i-2; j >= 2; j-=2)
			DP[i] += (j == 2 ? 3*DP[i-2] : 2*DP[i-j]);
		DP[i]+=2;
	}

	cin >> n;
	cout << DP[n];

	return 0;
}