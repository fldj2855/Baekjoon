#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

pair<int, int> q[100000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		q[i] = make_pair(a, b);
	}
	sort(q, q+n);
	for (int i = 0; i < n; i++)
		cout << q[i].first << " " << q[i].second << "\n";

	return 0;
}