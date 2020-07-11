#include<iostream>
#include<algorithm>
#include<string>
#define endl '\n'

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int k;
	cin >> k;

	cout << string(k, '1') << string(k-1, '0') << endl;

	return 0;
}