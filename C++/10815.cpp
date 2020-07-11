#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int A[500005];
int N, M;

bool bisearch(int find)
{
	int left = 0;
	int right = N-1;
	int mid;

	while(left <= right)
	{
		mid = (left + right)/2;

		if(A[mid] == find)
			return true;
		else if(A[mid] > find)
			right = mid-1;
		else if(A[mid] < find)
			left = mid+1;
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp;

	cin >> N;
	for(int i = 0; i < N; ++i)
		cin >> A[i];

	sort(A, A+N);

	cin >> M;
	for(int i = 0; i < M; ++i)
	{
		cin >> tmp;
		cout << bisearch(tmp) << ' ';
	}

	return 0;
}