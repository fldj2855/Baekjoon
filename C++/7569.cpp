#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

char box[105][105][105];
int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int N, M, H;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;

	for(int i = 0; i < H; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			for(int z = 0; z < M; ++z)
			{
				if(i == 0 || i == H+1 || j == 0 || j == N+1 || z == 0 || z == M+1)
					box[i][j][z] = '#';
				cin >> box[i+1][j+1][z+1];
			}
		}
	}

	for(int i = 0; i < H; ++i)
	{
		cout << i+1 << "floor" << endl;
		for(int j = 0; j < N; ++j)
		{
			for(int z = 0; z < M; ++z)
			{
				cout << box[i+1][j+1][z+1] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}


	return 0;
}