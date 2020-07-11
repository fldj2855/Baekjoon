#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define endl '\n'

using namespace std;

typedef vector<int> vi;
vi parent[100001];
int X[100001];
bool check[100001];

queue<int> q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	int x, y;
	cin >> t;
	for(int i = 0; i < t-1; ++i)
	{
		cin >> x >> y;
		parent[x].push_back(y);
		parent[y].push_back(x);
	}

	X[1] = 0;
	q.push(1);

	while(q.size())
	{
		int tmp = q.front();
		q.pop();
		
		for(auto n : parent[tmp])
		{
			if(!check[n])
			{
				check[n] = 1;
				X[n] = tmp;
				q.push(n);
			}
		}
	}

	for(int i = 2; i <= t; ++i)
		cout << X[i] << endl;

	return 0;
}