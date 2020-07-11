#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

// bool visited[100005];
int X[200005];

queue<int> q;

void BFS()
{
	int p;
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		if(p*2 < 200000 && X[p*2] == 0 || X[p] + 1 < X[p*2] )
		{
			X[p*2] = X[p] + 1;
			q.push(p*2);
		}
		if(X[p+1] == 0 || X[p] +1 < X[p+1])
		{
			X[p+1] = X[p] + 1;
			q.push(p+1);
		}
		if(X[p-1] == 0 || X[p] + 1 < X[p-1])
		{
			X[p-1] = X[p] + 1;
			q.push(p-1);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	// visited[n-1] = 1;
	// visited[n*2] = 1;
	// visited[n+1] = 1;

	q.push(n-1);
	q.push(n*2);
	q.push(n+1);

	BFS();

	cout << X[m] << endl;

	return 0;
}