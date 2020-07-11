#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int coin[105];
int M[10005];

int main(void)
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	int P;
	int i, j;

	cin >> n >> k;

	for(int i = 0; i < n; ++i)
		cin >> coin[i];

	// sort(coin, coin+n);

	for(i = 0; i < n; ++i)
	{
		P = coin[n-1-i];
		if(P <= k)
		{
			for(j = P; j <= k; ++j)
			{
				if(j%P == 0 && (M[j] == 0 || M[j] > M[j-P] + 1))
				{
					M[j] = M[j-P] + 1;
				}
				else
				{
					if(M[j-P] && (M[j] == 0 || M[j] > M[j-P] + 1))
						M[j] = M[j-P] + 1;
				}

			}
		}
	}
	
	// for(i = 1; i <= k; ++i)
	// 	cout << M[i] << ' ';

	// cout << endl;

	if(M[k])
		cout << M[k] << endl;
	else
		cout << "-1" << endl;

	return 0;
}