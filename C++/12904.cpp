#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

string reverse(string p)
{
	string res = "";

	for(int i = p.length()-1; i >= 0; --i)
		res += p[i];

	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	int blen, flen;

	string base;
	string last;
	cin >> base;
	cin >> last;

	blen = base.length();
	flen = last.length();

	while(blen < flen)
	{
		if(last[flen-1] == 'A')
			last = last.substr(0, flen-1);
		else
			last = reverse(last.substr(0, flen-1));

		flen-=1;
	}

	if(!base.compare(last))
		cout << "1" << endl;
	else
		cout << "0" << endl;

	return 0;
}