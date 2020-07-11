#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(void)
{
	int n;
	int t, f;
	int tmp;
	t = f = 0;

	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		tmp = i;
		while(tmp%2 == 0)
		{
			t++;
			tmp/=2;
		}
		tmp = i;
		while(tmp%5 == 0)
		{
			f++;
			tmp/=5;
		}
	}

	cout << f << endl;

	return 0;
}