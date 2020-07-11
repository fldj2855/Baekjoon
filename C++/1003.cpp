#include<iostream>
#include<algorithm>
#define endl '\n';

using namespace std;

int fi_z[45] = {1, 0, 1, 1, 2};
int fi_o[45] = {0, 1, 1, 2, 3};

/*
	fibo(2) -> fibo(1) + fibo(0)								# 1 1
	fibo(3) -> fibo(1) + fibo(0) + fibo(0)						# 2 1
	fibo(4) -> fibo(1) + fibo(0) + fibo(0) + fibo(1) + fibo(0)	# 3 2
*/

int main(void)
{
	int n, idx;
	cin >> n;

	for(int i = 5; i < 45; ++i)
	{
		fi_z[i] = fi_z[i-1] + fi_z[i-2];
		fi_o[i] = fi_o[i-1] + fi_o[i-2];
	}

	for(int i = 0; i < n; ++i)
	{
		cin >> idx;
		cout << fi_z[idx] << ' ' << fi_o[idx] << endl;
	}

	return 0;
}