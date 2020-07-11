#include<bits/stdc++.h>

using namespace std;

int A[1000005];
int N, M;

int MIN, MAX;

int bisearch()
{
	int left = 0;
	int right = INT_MAX;
	int mid;

	unsigned long long sum;
	int save;
	while(left <= right)
	{
		sum = 0;
		mid = (left+right)/2;
		for(int i = 0; i < N; ++i)
			if(A[i] - mid > 0)
				sum += A[i]-mid;
		
		if(sum == M)
			return mid;
		else if(sum > M)
		{
			save = mid;
			left = mid+1;
		}
		else if(sum < M)
			right = mid-1;
	}

	return save;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i < N; ++i)
		cin >> A[i];

	sort(A, A+N);

	cout << bisearch() << endl;

	return 0;
}