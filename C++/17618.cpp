#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int tmp;
	int cnt = 0;
	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		tmp = 0;
		m = i;
		while(m)
		{
			tmp += m%10;
			m/=10;
		}

		if(!(i%tmp))
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}