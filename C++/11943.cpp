#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int main(void)
{
	int apple, pineapple, apple2, pineapple2;

	cin >> apple >> pineapple;
	cin >> apple2 >> pineapple2;

	cout << min(apple+pineapple2, apple2+pineapple) << endl;

	return 0;
}