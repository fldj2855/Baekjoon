#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(void)
{
	int n = 9;
	int M, M_r;
	M = 0;
	M_r = 1;
	int tmp;
	int i =1;

	while(n--)
	{

		cin >> tmp;
		if(M < tmp)
		{
			M = tmp;
			M_r = i;
		}
		i++;
	}

	cout << M << endl << M_r << endl;

	return 0;
}