#include<bits/stdc++.h>

using namespace std;

unsigned long long C;
unsigned long long O;
unsigned long long W;

int main(void)
{
	int n;
	char ch;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> ch;
		if(ch == 'C')
			C++;
		else if(ch == 'O')
			O += C;
		else
			W += O;
	}

	cout << W << endl;

	return 0;
}