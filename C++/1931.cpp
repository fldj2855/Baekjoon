#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> V;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, s, e;
	int ans = 0;
	int save_start, save_last;

	save_start = save_last = 0;

	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		cin >> s >> e;
		V.push_back(pii(e, s));
	}

	sort(V.begin(), V.end());

	save_start = (*V.begin()).second;
	save_last = (*V.begin()).first;
	ans = 1;
	for(vector<pii>::iterator i = V.begin()+1; i != V.end(); i++)
	{
		if(/* (*i).first > save_last && */ (*i).second >= save_last)
		{
			// cout << save_start << ' ' << save_last << endl;
			ans++;
			save_start = (*i).second;
			save_last = (*i).first;
		}
		// cout << i.first << ' ' << i.second << endl;
	}

	cout << ans << endl;

	return 0;
}