#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int line[42];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	for(int i = 0; i < 10; ++i)
	{
		cin >> k;
		line[k%42]++;
	}

	k = 0;
	for(int i = 0; i < 42; ++i)
		if(line[i])
			k++;
	cout << k << endl;
	return 0;
}