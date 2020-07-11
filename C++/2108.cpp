#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int Ar[500005];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long sum = 0;
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		cin >> Ar[i];
		sum += Ar[i];
	}

	sort(Ar, Ar+N);




	return 0;
}