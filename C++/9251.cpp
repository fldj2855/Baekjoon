#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'

using namespace std;

string str1;
string str2;

int LCS[1005][1005];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;

	cin >> str1;
	cin >> str2;

	//LCS == LCS[strlen(str1)][strlen(str2)]

	for(int i = 0; i < str2.length(); ++i)
	{
		for(int j = 0; j < str1.length(); ++j)
		{
			if(str2[i] == str1[j])	LCS[i+1][j+1] = LCS[i][j]+1;
			else	LCS[i+1][j+1] = max(LCS[i][j+1], LCS[i+1][j]);
		}
	}

	cout << LCS[str2.length()][str1.length()] << endl;

	return 0;
}