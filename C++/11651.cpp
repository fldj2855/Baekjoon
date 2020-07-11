#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

typedef struct point
{
	int x, y;	
}P;

bool cmp(const P &p1, const P &p2){
    if(p1.x < p2.x){
        return true;
    }
    else if(p1.x == p2.x){
        return p1.y < p2.y;
    }
    else{
        return false;
    }
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	P array[100005];

	int N;
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		cin >> array[i].y >> array[i].x;
	}

	sort(array, array+N, cmp);


	for(int i = 0; i < N; ++i)
		cout << array[i].y << ' ' << array[i].x << endl;


	return 0;
}