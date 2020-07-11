#include<iostream>
#include<algorithm>
#include<cstring>
#define endl '\n'

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	char *p = NULL;
	int q;
	char S[81];
	cin >> n;

	while(n--)
	{
		cin >> S;

		for(p = S+1, q = 1; p < S + strlen(S)+1; ++p, ++q)
		{
			if(*p != *(p-1))
			{
				cout << q << ' ' << *(p-1) << ' ';
				q = 0;
			}
		}
		cout << endl;

		memset(S, 0, sizeof(S));
	}

	return 0;
}