#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int m;
	cin >> m;
	if(m <= 198)
		cout << min(198-m+1, m+1) << endl;
	else
		cout << 0 << endl;
}