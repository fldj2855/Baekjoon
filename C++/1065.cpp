#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, tmp, flag;
	int cnt = 0;

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		if( i < 100)
			cnt++;
		else
		{
			flag = 1;
			tmp = i;
			while(tmp/100)
			{
				if( !((tmp%10 - (tmp/10)%10 ) == ((tmp/10)%10 - (tmp/100)%10 )))
				{
					flag = 0;
				}
				tmp/=10;
			}

			if(flag)
				cnt++;
		}
	}

	cout << cnt;
}