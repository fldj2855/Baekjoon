#include <iostream>
#include <algorithm>
#include <math.h>
#define SQ(x) ((x)*(x))
#define endl '\n'

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double d;
	int n;
	cin >> n;
	int x1,x2,y1,y2,r1,r2;

	for(int i = 0; i < n; ++i)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = sqrt((SQ(x1-x2)+SQ(y1-y2)));

		if( x1 == x2 && y1 == y2)
		{
			if( r1 == r2)
				cout << "-1" << endl;
			else
				cout << "0" << endl;
		}
		else
		{
			if(r1+r2 < d)
				cout << "0" << endl;
			else if(r1+r2 == d)
				cout << "1" << endl;
			else
			{
				if(abs(r1-r2) == d)
					cout << "1" << endl;
				else if(abs(r1-r2) > d)
					cout << "0" << endl;
				else
					cout << "2" << endl;
			}
		}
	}

	return 0;
}