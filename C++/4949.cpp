#include<iostream>
#include<algorithm>
#include<string>
#include<stack>

#define endl '\n'

using namespace std;

bool M(const string& S)
{
	const string opening("(["), closing(")]");

	stack<char> Stack;
	for(int i = 0; i < S.size(); ++i)
	{
		if(opening.find(S[i]) != -1)
			Stack.push(S[i]);
		else if(closing.find(S[i]) != -1)
		{
			if(Stack.empty())	return false;
			if(opening.find(Stack.top()) != closing.find(S[i]))
				return false;

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

	while(1)
	{
		getline(cin, K);
		if(!K.compare("."))
			break;
		if(M(K))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}