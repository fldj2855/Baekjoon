#include<iostream>
#include<map>
#define endl '\n'
using namespace std;

bool E[1000020];

bool check(int n);
int eratos(int n);

int main(void)
{
	int n;
	cin >> n;
	eratos(n);
	for(int i = 2; i <= n; ++i)
	{
		check(i);
		// for(int j = 0; j < 30; ++j)
		// {
		// 	if(S[j] == '\0')
		// 		cout << ' ';
		// 	else
		// 		cout << S[j];
		// }
		// cout << endl;
	}

	for(int i = 2; i <= n; ++i)
	{
		if(E[i] == 0)
		{
			if(check(i))
			{
				cout << i << endl;
			}
		}
	}


	return 0;
}

bool check(int n)
{
	int tmp = n;
	int tmp2;
	map<int, char> S;
	while(1)
	{
		tmp2 = 0;
		while(tmp)
		{
			tmp2+=(tmp%10)*(tmp%10);
			tmp/=10;
		}

		if(tmp2 == 1)
			return true;
		
		if(!S.count(tmp2))
			S[tmp2] = 1;
		else
			return false;
		tmp = tmp2;
	}
}

int eratos(int n)
{
	for(int i = 2; i*i <= n; ++i)
	{
		for(int j = i*2; j <= n; j+=i)
		{
			E[j] = 1;
		}
	}
}