#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	char stack[1000005];
	int stack_len = 0;
	char bomb[105];

	cin >> S;
	cin >> bomb;

	int S_len = S.size();
	int bomb_len = strlen(bomb);

	for(int i = 0; i < S.size(); ++i)
	{
		stack[stack_len++] = S[i];

		if(bomb[bomb_len-1] == stack[stack_len-1])
		{
			if(!strncmp(stack + stack_len - bomb_len, bomb, bomb_len))
			{
				stack_len -= bomb_len;
			}
		}
	}
	stack[stack_len] = '\0';
	cout << stack << endl;

	return 0;
}