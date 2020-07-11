#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n';

using namespace std;

int N[100005];

int main(void)
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int x, y;

	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		N[x] += 1;
		N[y] += 1;
	}

	for(int i = 1; i <= n; ++i)
		cout << N[i] << endl;

	return 0;
}