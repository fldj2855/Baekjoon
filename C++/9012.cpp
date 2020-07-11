#include<iostream>
#include<algorithm>
#include<string>
#include<stack>

#define endl '\n'

using namespace std;

bool M(const string& S)
{
	const string opening("("), closing(")");
	stack<char> Stack;
	for(int i = 0; i < S.size(); ++i)
	{
		if(opening.find(S[i]) != -1)
			Stack.push(S[i]);
		else
		{
			if(Stack.empty())	return false;
			Stack.pop();
		}
	}
	return Stack.empty();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string K;
	int n;
	cin >> n;
	while(n--)
	{
		cin >> K;
		if(M(K))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}