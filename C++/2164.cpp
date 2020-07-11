#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>
#define endl '\n'

using namespace std;

int main(void)
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	if(n%2)
		cout << n << endl;
	else
		cout << n - n/3 << endl;

	return 0;
}