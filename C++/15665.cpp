#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int A[8];
int B[8];
int N, M;
int l;

void NM(int k)
{
	if(k == M)
	{
		for(int i = 0; i < M; ++i)
			cout << B[i] << ' ';
		cout << endl;
		return;
	}

	for(int i = 0; i < l; ++i)
	{
		B[k] = A[i];
		NM(k+1);
		B[k] = 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	cin >> N >> M;

	for(i = 0, l = 0; i < N; ++i)
	{
		cin >> A[l];
		for(j = 0; j < l; ++j)
			if(A[j] == A[l])
				break;
		if(l != j)
			A[l] = 0;
		else
			l++;
	}

	sort(A, A+l);

	NM(0);

	return 0;
}