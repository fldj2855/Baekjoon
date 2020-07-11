#include<iostream>
#include<algorithm>

using namespace std;

int dp[10];

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a=b;
		b=r;
	}
	return a;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, save_v = 987654321;

	for(int i = 0; i < 5; ++i)
		cin >> dp[i];

	for(int i = 0; i < 5-3+1; ++i)
	{
		for(int j = i+1; j < 5-2+1; ++j)
		{
			for(int z = j+1; z < 5-1+1; ++z)
			{
				v = 0;
				v = dp[i]*dp[j]/gcd(dp[i], dp[j]);
				v = v*dp[z]/gcd(v, dp[z]);

				if(save_v > v)
					save_v = v;
			}
		}
	}

	cout << save_v << endl;

	return 0;

}