#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#define endl '\n'

using namespace std;

long long int fibo[95] = {0, 1, 1};

int main(void)
{
	int n;
	cin >> n;
	for(int i = 3; i < 93; ++i)
		fibo[i] = fibo[i-1] + fibo[i-2];

	cout << fibo[n] << endl;

	return 0;
}