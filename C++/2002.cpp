#include<bits/stdc++.h>

using namespace std;

map<string, int> M;
stack<int> S;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt = 0;
	cin >> n;
	string tmp;
	for(int i = 1; i <= n; ++i)
	{
		cin >> tmp;
		M.insert(make_pair(tmp, i));
	}

	int idx = 0;
	while(idx < n)
	{
		cin >> tmp;
		int p = M.find(tmp)->second;
		while(!S.empty() && S.top() < p)
			S.pop();

		if(!S.empty() && S.top() > p)
		{
			cnt++;
			S.push(p);
		}
		else if(S.empty())
			S.push(p);

		idx++;
	}

	cout << cnt << endl;

	return 0;
}