#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int N, M;
	int tmp;
	char c;
	cin >> n >> c >> m;
	N = n;
	M = m;
	while(m)
	{
		tmp = n%m;
		n = m;
		m = tmp;
	}
	cout << N/n << ':' << M/n << endl;
	return 0;
}