#include<iostream>
#include<algorithm>
#include<math.h>
#define endl '\n'

using namespace std;

int N,r,c;
long long int cnt;

void z(int y, int x, int l)
{
	// cout << "[*] " << y << ' ' << x << ' '<< l << ' ' << cnt << endl;
	if(y == r && x == c)
	{
		cout << cnt << endl;
		return;
	}

	if(l >= 2)
	{
		if(r < y + l/2 && c < x + l/2)
		{
			return z(y + 0, x + 0, l/2);
		}
		else if(r < y + l/2 && c >= x + l/2)
		{
			cnt += (l/2)*(l/2);
			return z(y + 0, x + l/2, l/2);
		}
		else if(r >= y + l/2 && c < x + l/2)
		{
			cnt += 2*(l/2)*(l/2);
			return z(y + l/2, x + 0, l/2);
		}
		else if(r >= y + l/2 && c >= x + l/2)
		{
			cnt += 3*(l/2)*(l/2);
			return z(y + l/2, x + l/2, l/2);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	z(0, 0, pow(2, N));

	return 0;
}