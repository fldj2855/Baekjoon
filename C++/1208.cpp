#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int S[45];
int N, K;
int cnt;

int search(int e, int value, int t)
{
	if(value == K)
		cnt++;
	
	for(int i = e+1; i < N; ++i)
		search(i, value+S[i], t+1);
	
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for(int i = 0; i < N; ++i)
		cin >> S[i];

	for(int i = 0; i < N; ++i)
		search(i, S[i], 0);

	cout << cnt << endl;

	return 0;
}