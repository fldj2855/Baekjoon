#include<iostream>
#include<queue>
#include<utility>

using namespace std;

typedef pair<int, int> pii;
typedef queue< pair<int, int> > qpii;

bool visited[105][105];
int B[105][105];
int N, M, T;
int GRAM_X, GRAM_Y;

qpii Q;

void BFS()
{
	int Y[4] = {0, 0, 1, -1};
	int X[4] = {1, -1, 0, 0};
	int NY, NX;
	while(!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;

		Q.pop();

		for(int i = 0; !visited[y][x] && i < 4; ++i)
		{
			NY = y+Y[i];
			NX = x+X[i];
			
			if(0 <= NY && NY < N && 0 <= NX && NX < M)
			{
				if(B[NY][NX] != -1 && visited[NY][NX] == 0)
				{
					B[NY][NX] = B[y][x] + 1;
					Q.push(pii(NY, NX));
				}
			}
		}

		visited[y][x] = 1;
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			cin >> B[i][j];
			if(B[i][j] == 1)
				B[i][j]=-1;
			else if(B[i][j] == 2)
			{
				GRAM_Y = i;
				GRAM_X = j;
				B[i][j] = 0;
			}
		}
	}

	Q.push(pii(0,0));
	BFS();

	int GRAM = B[GRAM_Y][GRAM_X];
	int PRINCESS = B[N-1][M-1];

	if(GRAM)
	{
		if(PRINCESS)
			PRINCESS = min(PRINCESS, GRAM+(N-1-GRAM_Y) + (M-1-GRAM_X));
		else
			PRINCESS = GRAM + (N-1-GRAM_Y) + (M-1-GRAM_X);
	}
	
	if(PRINCESS == 0 || PRINCESS > T)
		cout << "Fail" << endl;
	else
		cout << PRINCESS << endl;
	
	return 0;
}
