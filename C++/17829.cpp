#include<iostream>
#include<algorithm>
#define endl '\n'
#define MAX(A, B) (A > B ? A : B)
#define MIN(A, B) (A < B ? A : B)
using namespace std;

int M[1030][1030];

int R(int i, int j)
{
	int tmp;
	int Q[4] = {M[i][j], M[i][j+1], M[i+1][j], M[i+1][j+1]};

	for(int x = 0; x < 3; ++x)
	{
		for(int y = x+1; y < 4; ++y)
		{
			if(Q[x] < Q[y])
			{
				tmp = Q[x];
				Q[x] = Q[y];
				Q[y] = tmp;
			}
		}
	}

	return Q[1];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> M[i][j];

	n/=2;
	while(n)
	{
		for(int i = 0;i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				M[i][j] = R(i*2, j*2);
			}
		}
		n/=2;
	}

	cout << M[0][0] << endl;

	return 0;
}
