#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int N;
int cnt = 0;
int flag;

void f(unsigned long long last, int k)
{
	if(k == 0)
	{
		if(cnt == N)
		{
			cout << last << endl;
			flag = 1;
		}
		cnt++;
		return;
	}

	for(int i = 0;!flag && i < last%10; ++i)
	{
		f(last*10 + i, k-1);
	}
}

int main(void)
{
	cin >> N;
	int k = 0;
	if(N == 0)
		cout << 0 << endl;
	else if(N >= 1023)
		cout << -1 << endl;
	else
	{
		while(cnt <= N)
		{
			for(int i = 0; i <= 9; ++i)
				f(i, k);
			k++;
		}
	}
	return 0;
}