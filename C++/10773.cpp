#include<iostream>
#include<algorithm>

using namespace std;

int k;
int stack[100005];
int stack_len;
long long int sum;
int v1;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;

	for(int i = 0; i < k; ++i)
	{
		cin >> v1;
		if(v1 == 0)
			stack[--stack_len] = 0;
		else
			stack[stack_len++] = v1;
	}

	for(int i = 0; i < stack_len; ++i)
		sum += stack[i];

	cout << sum << endl;
	
	return 0;
}