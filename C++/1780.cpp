#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int N;
int A[2200][2200];

int Minus, Zero, Plus;

int check(int y, int x, int k)
{
	int stan = A[y][x];
	for(int i = y; i < y+k; ++i)
	{
		for(int j = x; j < x+k; ++j)
		{
			if(stan != A[i][j])
				return 1;
		}
	}

	if(stan == -1)
		Minus += 1;
	else if(stan == 0)
		Zero += 1;
	else if(stan == 1)
		Plus += 1;

	return 0;
}

void P(int y, int x, int k)
{
	for(int i = y; i < y+3*k; i+=k)
	{
		for(int j = x; j < x+3*k; j+=k)
		{
			if(check(i, j, k))
			{
				P(i, j, k/3);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			cin >> A[i][j];
		}
	}

	if(check(0, 0, N))
		P(0, 0, N/3);

	cout << Minus << endl;
	cout << Zero << endl;
	cout << Plus << endl;


	return 0;
}