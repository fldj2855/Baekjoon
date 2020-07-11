#include<iostream>
#include<algorithm>
#define endl '\n'

int arr[10];	// backtracking array
int N, M;
int store[10];	// save number

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

	cin >> N >> M;

	for(int i = 0; i < N; ++i)
		cin >> store[i];
	
	sort(store, store+N);

	NM(0);

	return 0;
}
