#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	pii U[3], D[3];
	
	int N;
	cin >> N;

	cin >> D[0].first >> D[1].first >> D[2].first;
	D[0].second = D[0].first;
	D[1].second = D[1].first;
	D[2].second = D[2].first;

	for(int i = 1; i < N; ++i)
	{
		U[0] = D[0];
		U[1] = D[1];
		U[2] = D[2];
		
		cin >> D[0].first >> D[1].first >> D[2].first;
		D[0].second = D[0].first;
		D[1].second = D[1].first;
		D[2].second = D[2].first;

		D[0].first += max(U[0].first, U[1].first);
		D[1].first += max(U[0].first, max(U[1].first, U[2].first));
		D[2].first += max(U[1].first, U[2].first);

		D[0].second += min(U[0].second, U[1].second);
		D[1].second += min(U[0].second, min(U[1].second, U[2].second));
		D[2].second += min(U[1].second, U[2].second);
	}

	cout << max(D[0].first, max(D[1].first, D[2].first)) << " " << min(D[0].second, min(D[1].second, D[2].second));

	return 0;
}
