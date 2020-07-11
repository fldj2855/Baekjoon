#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int X[10][10];
bool B[10][10];	// 안쓰는 것 => 0

int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int check(int y, int x);

int main(void)
{
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			cin >> X[i][j];
			if(X[i][j])
				B[i][j] = 1;
		}
	}

	return 0;
}