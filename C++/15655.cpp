#include<iostream>
#include<algorithm>
#define endl '\n'

int isuse[10];	// used or not used
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
		if(!isuse[i] && arr[k-1] < store[i]) // [*] changed
		{
			isuse[i] = 1;			// used BIT on
			arr[k] = store[i];		// arr[k] = store[i].
			/*
			store[i] == 0 means store[i] is not used.
			so if will use value of store[i], turn store[i] BIT on.
			*/
			NM(k+1);
			isuse[i] = 0;			// if end of backtracking, turn used BIT off.
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
