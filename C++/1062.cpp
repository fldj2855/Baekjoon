#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int, int> pii;
map<int, pii> M;

int main(void)
{
	int ans = 0;
	int N, K, flag, save, cnt = 0;
	char tmp[16];
	int BIT;

	cin >> N >> K;

	while(N--)
	{
		save = BIT = 0;
		flag = 1;
		cnt = K;
		cin >> tmp;
		for(int i = 0; i < strlen(tmp); ++i)
		{
			if(!(BIT & (1 << (tmp[i]-'a'))))
			{
				cnt--;
				BIT += (1 << (tmp[i]-'a'));
			}
		}
		if(cnt < 0)
			continue;

		for(auto it = M.begin(); it != M.end(); ++it)
		{	
			if((it->first & BIT) == it->first)
				save++;
			if((it->first & BIT) == BIT && (it->second.second) < cnt)
				it->second.first += 1;
		}
		M[BIT] = pii(1 + save, cnt);
		for(auto it = M.begin(); it != M.end(); ++it)
		{
			cout << it->first << ' ' << it->second.first << ' ' << it->second.second << endl;
			// ans = max(it->second, ans);
		}
		cout << endl;
	}

	for(auto it = M.begin(); it != M.end(); ++it)
	{
		cout << it->first << ' ' << it->second.first << ' ' << it->second.second << endl;
		// ans = max(it->second, ans);
	}

	cout << ans << endl;

	return 0;
}