#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    ll lo, hi, mid, total_money=0;
    ll MIN = 0, ans = 0;
    ll money, money2, idx;
    vector<int> v;
    
    cin >> N;
    v.resize(N);

    for(int i = 0; i < N; ++i)
    {
        cin >> v[i];
        total_money += v[i];
    }

    cin >> money;
    sort(v.begin(), v.end());

    if(total_money <= money)
    {
        cout << v[N-1] << endl;
        return 0;
    }

    lo = 1; hi = money;

    while(lo <= hi)
    {
        mid = (lo + hi)/2;

        // cout << lo << " " << mid << " " << hi << endl;
        money2 = money;
        idx = 0;
        for(vector<int>::iterator i = v.begin(); i != v.end(); ++i, ++idx)
        {
            if(*i < mid)
                money2 -= *i;
            else
                break;
        }

        money2 -= (v.size() - idx)*mid;

        if(money2 < 0)
        {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << hi << endl;

    return 0;
}