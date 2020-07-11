#include<iostream>
#include<algorithm>
#define endl '\n'

using namespace std;

int dp[105] = {1};

typedef struct L
{
	int x, y;	
}L;

bool cmp(const L &p1, const L &p2){
    if(p1.x < p2.x){
        return true;
    }
    // else if(p1.x == p2.x){
    //     return p1.y < p2.y;
    // }
    else{
        return false;
    }
}

int main(void)
{
	L l[105];
	int n;
	int x, y;
	int mc, save_mc;
	mc = save_mc = 0;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> l[i].x >> l[i].y;
	
	sort(l, l+n, cmp);

	for(int i = 0; i < n; ++i)
	{
		mc = dp[0];
		for(int j = 0; j < i; ++j)
			if(l[i].y > l[j].y)
				mc = max(mc, dp[j]+1);
		dp[i] = mc;
		if(save_mc < mc)
			save_mc = mc;
	}

	cout << n-save_mc << endl;

	return 0;
}