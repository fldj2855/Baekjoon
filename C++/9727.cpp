#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int board[6][6];

int C(int &a, int k)
{
	if(a & ( 1 << k))
		return 1;
	else
		a += ( 1 << k);

	return 0;
}

int P()
{
	int r = 1;
	int a;
	for(int i = 0; i < 6; ++i)
	{
		a = 0;
		for(int j = 0; j < 6; ++j)
			if(C(a, board[i][j]))
				return 0;
	}

	for(int i = 0; i < 6; ++i)
	{
		a = 0;
		for(int j = 0; j < 6; ++j)
			if(C(a, board[j][i]))
				return 0;
	}

	for(int i = 0; i < 6; ++i)
	{
		if(i%2 == 0)
			a = 0;

		for(int j = 0; j < 3; ++j)
			if(C(a, board[i][j]))
				return 0;
	}

	for(int i = 0; i < 6; ++i)
	{
		if(i%2 == 0)
			a = 0;
		
		for(int j = 3; j < 6; ++j)
			if(C(a, board[i][j]))
				return 0;
	}

	a = 0;
	for(int i = 0; i < 6; ++i)
		if(C(a, board[i][i]))
			return 0;

	a = 0;
	for(int i = 0; i < 6; ++i)
		if(C(a, board[i][5-i]))
			return 0;

	return 1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for(int i = 1; i <= t; ++i)
	{
		for(int j = 0; j < 6; ++j)
		{
			for(int z = 0; z < 6; ++z)
			{
				cin >> board[j][z];
			}
		}

		cout << "Case#" << i << ": " << P() << endl;
	}

	return 0;
}