#include <bits/stdc++.h> 
#include<iostream>
#include<map>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
#define endl '\n';

using namespace std;

set<string> s;

int main(void)
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	string name;
	string log;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> name	>> log;
		if(!log.compare("enter"))
		{
			s.insert(name);
		}
		else
		{
			s.erase(name);
		}
	}

	for(set<string>::reverse_iterator iter = s.rbegin(); iter != s.rend(); ++iter)
		cout << *iter << endl;

	return 0;
}