#include<iostream>
#include<algorithm>
#include<cstring>
#define endl '\n'

using namespace std;

int X[2][2] = {{1, 2}, {3, 4}};
char str[1000005];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	int tmp;

	for(int i = 0; i < strlen(str); ++i)
	{
		// while(str[i] == str[i+1] && i < strlen(str))
		// 	i = i+2;
		
		
		if(str[i] == 'H')
		{
			tmp = X[0][0];
			X[0][0] = X[1][0];
			X[1][0] = tmp;

			tmp = X[0][1];
			X[0][1] =  X[1][1];
			X[1][1] = tmp;
		}
		else if(str[i] == 'V')
		{
			tmp = X[0][0];
			X[0][0] = X[0][1];
			X[0][1] = tmp;

			tmp = X[1][0];
			X[1][0] = X[1][1];
			X[1][1] = tmp;
		}
		
	}

	cout << X[0][0] << ' ' << X[0][1] << endl;
	cout << X[1][0] << ' ' << X[1][1] << endl;

	return 0;
}