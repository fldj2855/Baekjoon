#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

queue<int> Q;

int main(void)
{
	int N, K, tmp;
	cin >> N >> K;

	for(int i = 1; i <= N; ++i)
		Q.push(i);

	cout << '<';
	while(Q.size() != 1)
	{
		for(int i = 0; i < K-1; ++i)
		{
			tmp = Q.front();
			Q.pop();
			Q.push(tmp);
		}

		cout << Q.front() << ", ";
		Q.pop();
	}

	cout << Q.front() << ">" << endl;

	return 0;
}