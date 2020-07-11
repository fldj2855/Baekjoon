#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

string N[10005];
int cnt;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	int m;
	int l;

	string find;

	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		cin >> N[i];

	for(int i = 0; i < m; ++i)
	{
		cin >> find;
		for(int j = 0; j < n; ++j)
		{
			if(!N[j].compare(0, find.length(), find))
			{
				cnt++;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}