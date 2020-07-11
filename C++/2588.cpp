#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int main(void)
{
	int n, m;
	cin >> n;
	cin >> m;

	cout << n*(m%10) << endl;
	cout << n*((m%100)/10) << endl;
	cout << n*(m/100) << endl;
	cout << n*m << endl;


	return 0;
}