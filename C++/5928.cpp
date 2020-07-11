#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int main(void)
{
	int N = 11*24*60 + 11*60 + 11;

	int d, h, m;
	int M;
	cin >> d >> h >> m;
	M = d*24*60 + 60*h + m;

	if(M < N)
		cout << "-1" << endl;
	else
		cout << M-N << endl;

	return 0;
}