#include<iostream>
#include<algorithm>
#include<cstring>

#define endl '\n'

using namespace std;

int INPUT;
int return_MIN(int k);

int main(void)
{
	int n;
	int cnt = 0;

	for(int i = 0; i < 4; ++i)
	{
		cin >> n;
		INPUT*=10;
		INPUT+=n;
	}

	int X = return_MIN(INPUT);

	for(int i = 1111; i <= X; ++i)
		if(return_MIN(i) == i)
			cnt++;

	cout << cnt << endl;

	return 0;
}

int return_MIN(int k)
{
	int min = k;
	int i, j;
	for(i = 0; i < 3; ++i)
	{
		int tmp = k/1000;
		k%=1000;
		k*=10;
		k+=tmp;
		min = (k < min ? k : min);
	}

	return min;
}