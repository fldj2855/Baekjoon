#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

bool E[1000005];

int main(void)
{
	long long i, j;
	long long min ,max;

	cin >> min >> max;

	int n = max - min+1;
	int cnt = 0;

	for(i = 2; i*i <= max; ++i)
	{
		j = min;
		if(min%(i*i) == 0)
			j = min;
		else
			j = min + i*i - (min%(i*i));
		for(int k = 0;j + k*i*i <= max; ++k)
			E[j + k*i*i - min + 1] = 1;
	}

	for(i = 1; i <= n; ++i)
		cnt += (E[i] == 0 ? 1 : 0);

	cout << cnt << endl;

	return 0;
}