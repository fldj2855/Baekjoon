#include<bits/stdc++.h> 
#include<iostream>
#include<map>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
#define endl '\n';

using namespace std;

vector< pair<int, int> > v;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	vector< pair<int, int> >::iterator iter;
	int n;
	int x, y;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		for(iter = v.begin(); iter != v.end(); ++iter)
			cout << (*iter).first << ' ' << (*iter).second << endl;
		v.clear();
	}

	return 0;
}