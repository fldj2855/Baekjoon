#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#define endl '\n'

using namespace std;

char S[300005];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int i, j;
	int idx;
	int k;
	cin >> n >> m;

	for(i = 0; i < n; ++i)
	{
		cin >> idx;
		if(idx <= m)
		{
			// 0 --> 1
			for(j = m; j >= 1; --j)
			{
				if((S[j] & 1) && ((S[j+idx] & 2) == 0))	
					S[j+idx] += 2;
				if((S[j] & 2) && ((S[j+idx] & 4) == 0))
					S[j+idx] += 4;
			}

			if((S[idx] & 1) == 0)
				S[idx] = 1;
		}
	}

	// for(i = 0; i <= m; ++i)
	// 	cout << (int)S[i] << ' ';
	for(i = m; !(S[i] & 4); --i);
	cout << i << endl;


	return 0;
}