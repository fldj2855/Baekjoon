#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

typedef pair<int, int> pii;

pii P[1000005];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int v1, v2;

	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> v1 >> v2;
		P[i] = pii(v1, v2);
	}

	sort(P, P+n);

	int ret = 0;
	
	ret = P[0].second - P[0].first;
	int pre = P[0].second;

	for(int i = 1; i < n; ++i)
	{
		if(P[i].first <= pre && pre < P[i].second)
			ret += P[i].second - pre;
		else if(pre < P[i].first)
			ret += P[i].second - P[i].first;
		
		pre = max(pre, P[i].second);
		
	}

	cout << ret << endl;

	return 0;
}