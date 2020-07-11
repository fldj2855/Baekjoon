#include<iostream>
#include<math.h>

#define endl '\n'

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	int x, y;
	int len;
	long long i;

	cin >> t;
	while(t--)
	{
		cin >> x >> y;
		y-=x;
		x = 0;
		for( i = 1; i*i < y; ++i);

		cout << i + ceil(((double)y-i)/i) << endl;
	}

	return 0;
}