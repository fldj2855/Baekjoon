#include<iostream>
#include<algorithm>
#include<string>

#define CLOCKWISE 1
#define COUNTERCLOCKWISE -1

using namespace std;

char S[4][9];

void shift(int idx, int mode);
void s(int idx, int mode);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0; i < 4; ++i)
		cin >> S[i];

	int t;
	int idx, mode;
	cin >> t;
	while(t--)
	{
		cin >> idx >> mode;
		s(idx-1, mode);
	}

	int score = 0;
	for(int i = 0;i < 4; ++i)
		score += (S[i][0] == '0' ? 0 : 1 << i);
	
	cout << score << endl;

	return 0;
}

void shift(int idx, int mode)
{
	int tmp;
	if(mode == CLOCKWISE)
	{
		tmp = S[idx][7];
		for(int i = 7; i >= 0; --i)
			S[idx][i] = S[idx][i-1];
		S[idx][0] = tmp;
	}
	else if(mode == COUNTERCLOCKWISE)
	{
		tmp = S[idx][0];
		for(int i = 0; i < 7; ++i)
			S[idx][i] = S[idx][i+1];
		S[idx][7] = tmp;
	}
}

void s(int idx, int mode)
{
	if(idx == 0)
	{
		if(S[idx][2] != S[idx+1][6])
		{
			if(S[idx+1][2] != S[idx+2][6])
			{
				if(S[idx+2][2] != S[idx+3][6])
				{
					shift(idx+3, mode*-1);
				}
				shift(idx+2, mode);
			}
			shift(idx+1, mode*-1);
		}
	}
	else if(idx == 1)
	{
		if(S[idx][6] != S[idx-1][2])
			shift(idx-1, mode*-1);
		if(S[idx][2] != S[idx+1][6])
		{
			if(S[idx+1][2] != S[idx+2][6])
			{
				shift(idx+2, mode);
			}	
			shift(idx+1, mode*-1);
		}
	}
	else if(idx == 2)
	{
		if(S[idx][6] != S[idx-1][2])
		{
			if(S[idx-1][6] != S[idx-2][2])
			{
				shift(idx-2, mode);
			}
			shift(idx-1, mode*-1);
		}
		if(S[idx][2] != S[idx+1][6])
			shift(idx+1, mode*-1);
	}
	else if(idx == 3)
	{
		if(S[idx][6] != S[idx-1][2])
		{
			if(S[idx-1][6] != S[idx-2][2])
			{
				if(S[idx-2][6] != S[idx-3][2])
				{
					shift(idx-3, mode*-1);
				}
				shift(idx-2, mode);
			}
			shift(idx-1, mode*-1);
		}
	}

	shift(idx, mode);
}