#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

long long int f1bo[120] = {0, 1, 1, 1};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	for(int i = 4; i <= 116; ++i)
		f1bo[i] = f1bo[i-1] + f1bo[i-3];

	cin >> n;

	cout << f1bo[n] << endl;

	return 0;
}