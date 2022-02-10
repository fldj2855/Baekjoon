#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

long long memo[1000005];

void init()
{
	for(int i = 1; i <= 1000000; ++i)
	{
		for(int j = i; j <= 1000000; j += i)
			memo[j] += i;
	}

	for(int i = 2; i <= 1000000; ++i)
		memo[i] += memo[i-1];
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    
    int t, n;
    cin >> t;
    
    while(t--)
    {
        cin >> n;
        cout << memo[n] << endl;
    }
    return 0;
}