#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

int A, B;

int BFS()
{
	pii p;
	queue<pii> Q;
	Q.push(pii(B, 1));

	while(!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if(p.first == A)
			return p.second;
		if(p.first == 0)
			continue;
		if(p.first%10 == 1)
			Q.push(pii(p.first/10, p.second+1));
		if(p.first%2 == 0)
			Q.push(pii(p.first/2, p.second+1));
	}

	return -1;
}

int main()
{
	cin >> A >> B;

	cout << BFS() << endl;


	return 0;
}