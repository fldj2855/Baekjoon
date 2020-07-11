#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int N, M;
int cnt;

bool isuse[205];
bool V[205][205];
int arr[205];

int check(int l, int k)
{
	for(int i = 0; i < k; ++i)
	{
		if(V[arr[i]][l])
			return 0;
	}

	return 1;
}

void B(int k)
{
	if(k == 3)
	{
		cnt++;
		return;
	}

	for(int i = 1; i <= N; ++i)
	{
		if(isuse[i] == 0 && check(i, k) && arr[k-1] < i)
		{
			isuse[i] = 1;
			arr[k] = i;
			B(k+1);
			arr[k] = 0;
			isuse[i] = 0;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int v1, v2;

	for(int i = 0; i < M; ++i)
	{
		cin >> v1 >> v2;
		V[v1][v2] = V[v2][v1] = 1;
	}

	B(0);

	cout << cnt << endl;

	return 0;
}