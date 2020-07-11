#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{

	int total = 0;
	int s;
	
	for(int i = 0; i < 4; ++i)
	{
		cin >> s;
		total += s;
	}
	
	cout << total/60 << '\n' << total%60 << endl;

	return 0;
}