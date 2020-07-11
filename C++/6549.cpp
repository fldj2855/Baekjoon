#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

typedef vector<int> vi;
typedef stack<int> si;

long long unsigned int S(int n);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;
	while(1)
	{
		cin >> n;
		if(n == 0)
			break;
		else
			cout << S(n) << endl;
	}

	return 0;
}

long long unsigned int S(int n)
{
	vi height;
	si idx;

	int k;
	long long unsigned int ret = 0;

	for(int i = 0; i < n; ++i)
	{
		cin >> k;
		height.push_back(k);
	}

	height.push_back(0);
	for(int i = 0; i < height.size(); ++i)
	{
		while(!idx.empty() && height[idx.top()] >= height[i])
		{
			int j = idx.top();
			idx.pop();
			int width = -1;

			if(idx.empty())
				width = i;
			else
				width = (i - idx.top() - 1);

			ret = max(ret, (long long unsigned int)height[j] * width);
		}
		idx.push(i);
	}

	return ret;
}