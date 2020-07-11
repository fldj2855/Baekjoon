#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i=i+6)
		cnt++;
	
	cout << cnt << endl;


	return 0;
}