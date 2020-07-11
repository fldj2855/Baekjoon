#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int isuse2[10];
int isuse[10];
int n, m;
int arr[10];

void NM(int k);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	NM(0);

	return 0;
}

void NM(int k)
{

	if(k == m)
	{
		for(int i = 0; i < k; ++i)
			cout << arr[i] << ' ';
		cout << endl;
		return;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!isuse[i])	//만약 사용하지않는다면 
		{
			arr[k] = i;
			isuse[i] = 1;
			NM(k+1);
			isuse[i] = 0;
		}
	}

}