#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int D[2][8]={
	{1, -1, 5, 2, 1, 5, 5, 6},
	{7, 0, 0, 3, 3, 4, -1, -1}
};

int main(void)
{
	int t;
	int n;
	string tmp;
	cin >> t;

	while(t--)
	{
		n = 0;
		cin >> tmp;

		for(int i = 0; i < tmp.length() && n != -1; ++i)
			n = D[tmp[i]-'0'][n];
		
		if(n == 0 || n == 4 || n == 3)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}