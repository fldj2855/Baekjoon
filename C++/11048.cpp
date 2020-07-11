#include<iostream>
#include<algorithm>
#define MAX(A, B) (A > B ? A : B)
#define endl '\n'

using namespace std;

int M[1005][1005];

int main(void)
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int k;
	int n, m; cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> k;
			M[i][j] = k;
			if(i == 0 && j > 0)
				M[i][j] += M[i][j-1];
			if(j == 0 && i > 0)
				M[i][j] += M[i-1][j];
			if(i > 0 && j > 0)
				M[i][j] += MAX(M[i][j-1], M[i-1][j]);
		}
	}

	// for(int i = 0; i < n; ++i)
	// {
	// 	for(int j = 0; j < m; ++j)
	// 	{
	// 		cout << M[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	cout << M[n-1][m-1] << endl;

	return 0;
}