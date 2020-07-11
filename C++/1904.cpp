#include<iostream>
#include<algorithm>
#include<map>
#include<utility>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	
	int x = 1, y = 1;
	int tmp;
	cin >> n;

	while(n--)
	{
		tmp = x+y;
		x = y;
		y = tmp%15746;
	}

	cout << x << endl;	
	return 0;
}