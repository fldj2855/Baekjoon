#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	if(n == m)
		cout << "==" << endl;
	else
		cout << (n > m ? '>' : '<') << endl;

	return 0;
}