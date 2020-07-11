#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

bool eratos[2000005];

void E()
{
	for(int i = 2; i*2 <= 2000005; ++i)
	{
		if(!eratos[i])
		{
			for(int j = i*2; j <= 2000005; j += i)
				eratos[j] = 1;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	E();

	int n;
	int T;
	cin >> n;
	while(n--)
	{
		cin >> T;
		for(int i = 0; i < T-1; ++i)
		{
			if(!eratos[T+i] && !eratos[T-i])
			{
				cout << T-i << ' ' << T+i << endl;
				break;
			}
		}
	}

	return 0;
}
