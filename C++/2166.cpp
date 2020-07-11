#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef struct point
{
	long long y, x;
}P;

P p[10005];

int main(void)
{
	long long SUM = 0;
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> p[i].x >> p[i].y;
	}

	for(int i = 0; i < N; ++i)
	{
		SUM += p[i].x*p[(i+1)%N].y;
	}

	for(int i = 0; i < N; ++i)
	{
		SUM -= p[(i+1)%N].x*p[i].y;
	}

	printf("%.1lf\n", (double)abs(SUM)/2.0);

	return 0;
}