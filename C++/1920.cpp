#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int N, A[100005], M;

int bisearch(int find)
{
	int start = 0;
	int end = N-1;
	int mid;

	while(start <= end)
	{
		mid = (end + start)/2;
		if(A[mid] == find)
			return 1;
		else if(A[mid] < find)
			start = mid+1;
		else if(A[mid] > find)
			end = mid-1;
	}

	return 0;
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
		cout << bisearch(tmp) << endl;
	}

	return 0;
}