#include <iostream>
#include <vector>
//#include <unordered_set>
#include <algorithm>
#include <queue>
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'
#define ll long long
#define mp(a,b) make_pair(a,b)
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
#define MAX 200000000
#define pii pair<int, int>

using namespace std;

int main(void)
{
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	q.pop();

	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.size() <<endl;
	cout << q.empty() << endl;
}