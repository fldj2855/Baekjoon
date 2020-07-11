#include<iostream>
#include<algorithm>
#include<cstring> // for memset
#define endl '\n'

using namespace std;
int cycle[1005];
bool memo[1005];
int T;

int dfs(int start, int end, int n)
{
	for(int i = 1; i <= n; ++i)
	{
		end = cycle[end];
		memo[end] = 1;
		if(start == end)
			return 1;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int cnt;
	cin >> T;
	for(int i = 0; i < T; ++i)
	{
		cnt = 0;
		cin >> n;
		for(int j = 1 ; j <= n; ++j)
		{
			cin >> cycle[j];
		}	

		for(int j = 1; j <= n; ++j)
			if(!memo[j])
				cnt += dfs(j, j, n);
		
		cout << cnt << endl;
		memset(cycle, 0, sizeof(cycle));
		memset(memo, 0, sizeof(memo));
	}

	return 0;
}
