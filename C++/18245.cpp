#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

string str;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int seq = 2;
	while(1)
	{
		getline(cin,str);
		if(str == "Was it a cat I saw?")
			break;
		else
		{
			int k = str.size();
			for(int i = 0; i < k; i += seq)
				cout << str[i%k];
			cout << endl;
			seq++;
		}
	}

	return 0;
}