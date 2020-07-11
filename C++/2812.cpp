#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

string NUMBER;

int main(void)
{
	int start, end;
	int N, K;
	cin >> N >> K;
	cin >> NUMBER;

	start = 0;
	while(NUMBER[start] > NUMBER[start+1])
		start++;

	for(int i = start;K && i < NUMBER.size(); ++i)
	{
		if(NUMBER[start] <= NUMBER[i+1])
		{
			NUMBER[start] = '#';
			K--;
			start--;
		}
		if(start < 0)
			break;
	}

	start = NUMBER.size()-1;
	while(NUMBER[start - 1] < NUMBER[start] )
		start--;

	for(int i = start;K && i >= 0; --i)
	{
		if(NUMBER[i-1] >= NUMBER[start])
		{
			NUMBER[start] = '#';

		}
	}

	for(int i = 0; i < NUMBER.size(); ++i)
	{
		if(NUMBER[i] != '#')
			cout << NUMBER[i];
	}
	return 0;
}