#include<iostream>
#include<algorithm>
#define endl '\n'

int A[8];
int B[8];
int N, M;
int l;

using namespace std;

void NM(int k){

	if(k == M)	// if k == M, arr is fulled.
	{
		for(int i = 0; i < k; ++i)	// print arr
			cout << arr[i] << ' ';
		cout << endl;
		return;						// return
	}

	for(int i = 0; i < N; ++i)
	{
		if(arr[k-1] <= store[i])
		{
			arr[k] = store[i];		// arr[k] = store[i].
			NM(k+1);
		}
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
