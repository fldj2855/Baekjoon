#include<bits/stdc++.h>

using namespace std;

#define endl '\n';

int A[25];
bool isuse[15];
int cnt;

int N, X, Y;

void R(int x)
{
	if(x == 2*N)
	{
		cnt++;
		return;
	}

	if(A[x] == 0)
	{
		for(int i = 1; i <= N; ++i)
		{
			if(isuse[i] == 0 && x+i+1 <= 2*N && A[x+i+1] == 0)
			{
				A[x] = A[x+i+1] = i;
				isuse[i] = 1;
				R(x+1);
				isuse[i] = 0;
				A[x] = A[x+i+1] = 0;
			}
		}
	}
	else
		R(x+1);

}

int main(void)
{
	int i;
	cin >> N >> X >> Y;

	isuse[Y-X-1] = 1;
	A[X] = A[Y] = Y-X-1;

	R(1);

	cout << cnt;

	return 0;
}