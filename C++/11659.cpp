#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int X[100005];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int x1, x2;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i)	
		cin >> X[i];

	for(int i = 2; i <= n; ++i)
		X[i] += X[i-1];

	for(int i = 0; i < m; ++i)
	{
		cin >> x1 >> x2;
		x1-=1;
		x2;
		cout << X[x2] - X[x1] << endl;
	}

	return 0;
}