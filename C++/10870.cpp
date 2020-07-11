#include<iostream>
#include<algorithm>

using namespace std;

int memo[25] = {0, 1, 1};

int fibo(int n)
{
	if(memo[n] || n == 0)
		return memo[n];

	return memo[n] = fibo(n-1) + fibo(n-2);
}

int main(void)
{
	int n;

	cin >> n;
	fibo(n);
	cout << memo[n] << endl;

	return 0;
}