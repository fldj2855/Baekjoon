#include<bits/stdc++.h>

using namespace std;

typedef struct bit
{
	long long index;
	long long value;
}bit;

bit BIT[60];
int len;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, K;
	long long res = 0;

	cin >> N >> K;

	long long stan = 0;
	for(int i = 0; len < 60; ++i)
	{
		stan = (long long)pow(2, i);
		if((stan & N) == 0)
		{
			BIT[len] = {(long long)pow(2,len), stan};
			len++;
		}
	}

	// DEBUG
	// for(int i = 0; i < len; ++i)
	// 	cout << BIT[i].index << ' ' << BIT[i].value << endl;

	// COUNT
	for(int i = len-1; i >= 0; --i)
	{
		if(BIT[i].index <= K)
		{
			// cout << BIT[i].value << endl;
			K -= BIT[i].index;
			res += BIT[i].value;
		}
	}

	assert(res + N == res | N);
	cout << res << endl;

	return 0;
}