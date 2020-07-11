#include<iostream>
#include<string>
#include<queue>

#define endl '\n'

using namespace std;

queue<int> Q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int t;
	cin >> t;

	while(t--)
	{
		cin >> str;
		if(!str.compare("push"))
		{
			int tmp;
			cin >> tmp;
			Q.push(tmp);
		}
		else if(!str.compare("front"))
		{
			if(Q.empty())
				cout << -1 << endl;
			else
				cout << Q.front() << endl;
		}
		else if(!str.compare("back"))
		{
			if(Q.empty())
				cout << -1 << endl;
			else
				cout << Q.back() << endl;
		}
		else if(!str.compare("size"))
		{
			cout << Q.size() << endl;
		}
		else if(!str.compare("empty"))
		{
			cout << Q.empty() << endl;
		}
		else if(!str.compare("pop"))
		{
			if(Q.empty())
				cout << -1 << endl;
			else
			{
				cout << Q.front() << endl;
				Q.pop();
			}
		}
	}

	return 0;
}