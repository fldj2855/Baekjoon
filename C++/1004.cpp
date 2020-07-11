#include<iostream>
#include<math.h>

#define endl '\n'

using namespace std;

int T;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int p_x, p_y, p_r;
	int x1,x2,y1,y2;
	int p;
	int cnt;

	cin >> T;
	while(T--)
	{
		cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> p;
		while(p--)
		{
			cin >> p_x >> p_y >> p_r;
			long long int X = (p_x-x1)*(p_x-x1)+(p_y-y1)*(p_y-y1);
			long long int Y = (p_x-x2)*(p_x-x2)+(p_y-y2)*(p_y-y2);
			long long int R = p_r*p_r;
			if((X-R)*(Y-R) <= 0)
				cnt++;

		}
		cout << cnt << endl;
	}

	return 0;
}