#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;

	cin >> n;

	string k = new string[n];

	for(int i = 0; i < n; ++i)
		cin >> k[i];

	sort(k, k+n);

	for(int i = 0; i < n; ++i)
		cout << k[i];

	return 0;
}