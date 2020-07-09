#include<bits/stdc++.h>
#define abs(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

typedef unsigned long long ull;

ull H[300005] = {0};
ull gap[300005] = {0};

ull calc_blocks(ull x, int size)
{
	ull result = 0;

	int mid = size/2;

	for(int i = 1; i < mid; ++i)
	{
		result += abs(gap[mid-i] - (x+i));
		result += abs(gap[mid+i] - (x+i));
	}

	return result;
}

ull need_blocks(ull s, ull e, int size)
{
	ull min_blocks = -1;
	ull mid, tmp_blocks;

	for(int i = 0; i < size; ++i)
	{
		cin >> H[i];
		gap[i] = (i <= size/2 ? abs(size-H[i]) : abs(H[i]-size));
	}

	for(ull i = 0; i < size; ++i)
		printf("%lld ", gap[i]);
	// while(s < e)
	// {
	// 	mid = (s+e)/2;
	// 	tmp_blocks = calc_blocks(mid, size);

	// 	if(tmp_blocks < min_blocks)
	// 		min_blocks = tmp_blocks;

	// 	if()
	// }

	return min_blocks;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	// for(int i = 0; i < N; ++i)
	// 	cin >> H[i];

	need_blocks(0, 1000000000000, N);

	return 0;
}