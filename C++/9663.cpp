#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int N[20][20];
int n;
int cnt;

void fill(int y, int x);
void clear(int y, int x);
void check(int k);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	check(0);

	cout << cnt << endl;

	return 0;	
}

void fill(int y, int x)
{
	int tmp_y = y;
	int tmp_x = x;

	while((0 < y) && (0 < x))
		{y--;x--;}
	while((0 <= y && y < n) && (0 <= x && x < n))
		N[y++][x++]+=1;

	y = tmp_y;
	x = tmp_x;
	
	while((0 < y) && (x < n-1))
		{y--;x++;}
	while((0 <= y && y < n) && (0 <= x && x < n))
		N[y++][x--]+=1;

	y = tmp_y;
	x = tmp_x;

	while((0 < y))
		y--;
	while((0 <= y && y < n) && (0 <= x && x < n))
		N[y++][x]+=1;
	
	y = tmp_y;
	x = tmp_x;
	
	while((0 < x))
		x--;
	while((0 <= y && y < n) && (0 <= x && x < n))
		N[y][x++]+=1;

	N[tmp_y][tmp_x]-=3;
}

void clear(int y, int x)
{
	int tmp_y = y;
	int tmp_x = x;

	while((0 < y) && (0 < x))
		{y--;x--;}
	while((0 <= y && y < n) && (0 <= x && x < n))
		N[y++][x++]-=1;

	y = tmp_y;
	x = tmp_x;
	
	while((0 < y) && (x < n-1))
		{y--;x++;}
	while((0 <= y && y < n) && (0 <= x && x < n))
		N[y++][x--]-=1;

	y = tmp_y;
	x = tmp_x;

	while((0 < y))
		y--;
	while((0 <= y && y < n) && (0 <= x && x < n))
		N[y++][x]-=1;
	
	y = tmp_y;
	x = tmp_x;
	
	while((0 < x))
		x--;
	while((0 <= y && y < n) && (0 <= x && x < n))
		N[y][x++]-=1;

	N[tmp_y][tmp_x]+=3;
}

void check(int k)
{
	if(k == n)
	{
		cnt++;
		return;
	}

	for(int i = 0; i < n; ++i)
	{
		if(N[k][i] == 0)
		{
			fill(k, i);
			check(k+1);
			clear(k, i);
		}
	}
}