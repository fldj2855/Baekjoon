#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

int main(void)
{
	IO;
	int a1, a2, a3;

	while(1)
	{
		cin >> a1 >> a2 >> a3;
		if(!a1 && !a2 && !a3)
			break;
		if(a2 - a1 == a3 - a2)
			cout << "AP " << a3 + (a2- a1) << endl;
		else
			cout << "GP " << a3 * (a3 - a2)/(a2 - a1) << endl;
	}

	return 0;
}