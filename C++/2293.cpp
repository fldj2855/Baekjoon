#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int money[100];
int M[10005] = {1};

int main(void)
{
	int N, K;
	int tm;
	cin >> N >> K;

	int n = 0;
	while(N--)
	{
		cin >> tm;
		if(tm <= K)
			money[n++] = tm;
	}

	sort(money, money+n);

	for(int i = 0; i < n; ++i)
	{
		for(int j = money[i]; j <= K; ++j)
		{
			M[j] += M[j - money[i]];
		}
	}

	cout << M[K] << endl;

	return 0;
}