#include<iostream>
#include<algorithm>
#define endl '\n'
#define MAX(A, B) (A > B ? A : B)

using namespace std;

int dp[2][100005];
int N[2][100005];

int main(void)
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, n;
	cin >> T;
	for(int i = 0; i < T; ++i)
	{
		cin >> n;
		for(int j = 0; j < 2; ++j)
		{
			for(int z = 0; z < n; ++z)
			{
				cin >> N[j][z];
			}
		}

		dp[0][0] = N[0][0];
		dp[1][0] = N[1][0];
		if(n == 1)
		{
			cout << MAX(N[0][0], N[0][1]) << endl;
		}
		else
		{
			dp[0][1] = N[1][0] + N[0][1];
			dp[1][1] = N[0][0] + N[1][1];

			for(int j = 2; j < n; ++j)
			{
				dp[0][j] = MAX(dp[1][j-1], dp[1][j-2])+N[0][j];
				dp[1][j] = MAX(dp[0][j-1], dp[0][j-2])+N[1][j];
			}
		}

		// for(int i = 0; i < 2; ++i)
		// {
		// 	for(int j = 0; j < n; ++j)
		// 		cout << dp[i][j] << ' ';
		// 	cout << endl;
		// }
		cout << MAX(dp[0][n-1],dp[1][n-1]) << endl;
	}


	return 0;
}
