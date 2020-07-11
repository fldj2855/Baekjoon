#include<iostream>
#include<stdlib.h>

#define endl '\n'

using namespace std;

 ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄▄▄▄▄▄▄▄▄▄▄ 
▐░░░░░░░░░░░▌▐░▌          ▐░░░░░░░░░░░▌
 ▀▀▀▀█░█▀▀▀▀ ▐░▌          ▐░█▀▀▀▀▀▀▀▀▀ 
     ▐░▌     ▐░▌          ▐░▌          
     ▐░▌     ▐░▌          ▐░█▄▄▄▄▄▄▄▄▄ 
     ▐░▌     ▐░▌          ▐░░░░░░░░░░░▌
     ▐░▌     ▐░▌          ▐░█▀▀▀▀▀▀▀▀▀ 
     ▐░▌     ▐░▌          ▐░▌          
     ▐░▌     ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ 
     ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌
      ▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀ 
                                       

int board[15][15];
int n;
int cnt;
int max_cnt=0;

// char FILL[]="[*] FILL";
// char CLEAR[]="[*] CLEAR";
void fill(int y, int x);
void clear(int y, int x);
void check();
void P(char *S);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> tmp;
			if(tmp == 1)
				board[i][j] = 0;
			else
				board[i][j] = -1;
		}
	}

	check();

	// cout << cnt << endl;
	cout << max_cnt << endl;

	return 0;
}

void fill(int y, int x)
{
	int tmp_y = y;
	int tmp_x = x;

	while((0 < y) && (0 < x)){y--;x--;}
	while((0 <= y && y < n) && (0 <= x && x < n))
	{
		if(board[y][x] != -1)
			board[y++][x++]+=1;
		else if(board[y][x] == -1)
		{
			y++;x++;
		}
	}

	y = tmp_y;
	x = tmp_x;

	while((0 < y) && (x < n-1)){y--;x++;}
	while((0 <= y && y < n) && (0 <= x && x < n))
	{
		if(board[y][x] != -1)
			board[y++][x--]+=1;
		else if(board[y][x] == -1)
		{
			y++;x--;
		}
	}

	board[tmp_y][tmp_x]-=1;
}

void clear(int y, int x)
{
	int tmp_y = y;
	int tmp_x = x;

	while((0 < y) && (0 < x)){y--;x--;}
	while((0 <= y && y < n) && (0 <= x && x < n))
	{
		if(board[y][x] != -1)
			board[y++][x++]-=1;
		else
		{
			y++;x++;
		}
	}

	y = tmp_y;
	x = tmp_x;

	while((0 < y) && (x < n-1)){y--;x++;}
	while((0 <= y && y < n) && (0 <= x && x < n))
	{
		if(board[y][x] != -1)
			board[y++][x--]-=1;
		else
		{
			y++;x--;
		}
	}

	board[tmp_y][tmp_x]+=1;
}

void check()
{
	if(max_cnt < cnt)
		max_cnt = cnt;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(!board[i][j])
			{
				cnt++;
				fill(i, j);
				// P(FILL);
				check();

				clear(i, j);
				cnt--;
				// P(CLEAR);
			}
		}
	}	
}

// DEBUG
void P(char *S)
{
	// system("clear");
	// char a;
	cout << S << endl;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << cnt << endl;
	cout << endl;
	// a = getchar();
}