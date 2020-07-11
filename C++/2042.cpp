/*

reference : https://www.acmicpc.net/blog/view/9

*/

#include<bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int N, M, K;

ll init(vll &a, vll &tree, int node, int start, int end)
{
	if(start == end)
		return tree[node] = a[start];
	else
	{
		// tree[node] == sum(node*2 ~ node*2 + 1)
		return tree[node] = init(a, tree, node*2, start, (start + end)/2) + init(a, tree, node*2+1, (start + end)/2 + 1, end);
	}
}

void update(vll &tree, int node, int start, int end, int index, long long diff)
{
	if(index < start || end < index)	return;
	tree[node] = tree[node] + diff;
	if (start != end)	// leap
	{
		update(tree, node*2, start, (start+end)/2, index, diff);
		update(tree, node*2+1, (start+end)/2 + 1, end, index, diff);
	}
}

ll sum(vll &tree, int node, int start, int end, int left, int right)
{
	if(right < start || end < left)
		return 0;
	if( left <= start && end <= right)
		return tree[node];
	return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	int t1, t2, t3;
	int query = M + K;

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h+1));

	vll a(N);
	vll tree(tree_size);

	for(int i = 0; i < N; ++i)
		cin >> a[i];

	init(a, tree, 1, 0, N-1);

	while(query--)
	{
		int t1;
		cin >> t1;
		if(t1 == 1)	// update
		{
			int t2;
			ll t3;
			cin >> t2 >> t3;
			t2-=1;
			ll diff = t3-a[t2];
			a[t2] = t3;
			update(tree, 1, 0, N-1, t2, diff);
		}
		else if(t1 == 2)
		{
			int t2, t3;
			cin >> t2 >> t3;
			cout << sum(tree, 1, 0, N-1, t2-1, t3-1) << endl;
		}
	}

	return 0;
}