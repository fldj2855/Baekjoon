#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

int building[1000005];
int F;
int S, G;
int U, D;

void BFS()
{
	pii p;
	queue<pii> Q;
	building[S] = 1;
	Q.push(pii(S, 1));

	int current_floor;
	int time;

	while(!Q.empty())
	{
		if(building[G])
			return;
		p = Q.front(); Q.pop();
		current_floor = p.first;
		time = p.second;

		if(current_floor + U <= F && building[current_floor + U] == 0)
		{
			building[current_floor + U] = time+1;
			Q.push(pii(current_floor+U, time+1));
		}
		if(1 <= current_floor - D && building[current_floor - D] == 0)
		{
			building[current_floor - D] = time+1;
			Q.push(pii(current_floor-D, time+1));
		}
	}

}

int main()
{
	cin >> F >> S >> G >> U >> D;

	BFS();

	if(building[G])
		cout << building[G]-1 << endl;
	else
		cout << "use the stairs" << endl;
	return 0;
}