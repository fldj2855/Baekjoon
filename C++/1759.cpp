#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int L, C;
char A[20];

int check(string S)
{
	string MO = "aeiou";
	string JA = "bcdfghjklmnpqrstvwxyz";
	int ja_flag = 0;
	int mo_flag = 0;

	for(int i =0; i < 5; ++i)
		if(S.find(MO[i]) != -1)
			mo_flag++;

	if(mo_flag < 1)
		return 0;

	for(int i =0 ; i < 21; ++i)
		if(S.find(JA[i]) != -1)
			ja_flag++;

	if(ja_flag < 2)
		return 0;

	return 1;
}
void trace(string S, int k)
{
	if(k == 0)
	{
		if(check(S))
			cout << S << endl;;
		return;
	}

	for(int i = 0; i < C; ++i)
	{
		if(S[S.size()-1] < A[i])
		{
			trace(S + A[i], k-1);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;
	for(int i = 0; i < C; ++i)
		cin >> A[i];

	sort(A, A+C);

	trace("", L);


	return 0;
}