#include<bits/stdc++.h>

using namespace std;

#define endl '\n';

int stan_alpha['z'-'a'+1];
int stan_ALPHA['z'-'a'+1];

int alpha['z'-'a'+1];
int ALPHA['Z'-'A'+1];

int check();

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s;
	string needle;
	string hay;
	int count = 0;
	int start, end;
	start = end = 0;

	cin >> n >> s;
	cin >> needle;

	for(int i = 0; i < n; ++i)
	{
		if('a' <= needle[i] && needle[i] <= 'z')
			stan_alpha[needle[i]-'a']+=1;
		else
			stan_ALPHA[needle[i]-'A']+=1;
	}

	cin >> hay;


	for(end = 0; end < n; ++end)
	{
		if('a' <= hay[end] && hay[end] <= 'z')
			alpha[hay[end] - 'a']+=1;
		else
			ALPHA[hay[end] - 'A']+=1;
	}
	
	count += check();
	while(end < s)
	{
		if('a' <= hay[start] && hay[start] <= 'z')
			alpha[hay[start] - 'a']-=1;
		else
			ALPHA[hay[start] - 'A']-=1;
		start += 1;
		if('a' <= hay[end] && hay[end] <= 'z')
			alpha[hay[end] - 'a'] += 1;
		else
			ALPHA[hay[end] - 'A'] += 1;
		end += 1;

		count += check();
	}

	cout << count;

	return 0;
}

int check()
{
	for(int i = 0; i < 'z'-'a'+1; ++i)
	{
		if(stan_ALPHA[i] != ALPHA[i])
			return 0;
		if(stan_alpha[i] != alpha[i])
			return 0;
	}

	return 1;
}