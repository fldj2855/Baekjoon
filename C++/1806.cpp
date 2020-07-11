#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int N, K;

int A[100005];

int main(void)
{
	unsigned long long sum = 0;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);

	int start, end;
	int ans = 987654321;
	start = end = 0;

	for(int i = 0; i < N; ++i)
	{
		while(sum < K && end < N)
			sum += A[end++];

		if(K <= sum && end - start < ans)
			ans = end - start;

		sum -= A[start++];
	}
	if(ans = 987654321)
		printf("%d\n", 0);
	else
		printf("%d\n", ans);

	return 0;
}