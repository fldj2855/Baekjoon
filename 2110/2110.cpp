#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, C;
    ll lo, hi, mid, x;
    ll prev, cnt;

    vector<ll> v;

    cin >> N >> C;

    v.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    lo = 0; hi = v[N-1] - v[0];

    while(lo <= hi)
    {
        mid = (lo + hi)/2;
        // cout << lo << " " << hi << endl;

        cnt = 1;
        prev = v[0];
        for(int i = 1; i < N; ++i)
        {
            if(mid <= v[i] - prev)
            {
                cnt++;
                prev = v[i];
            }
        }

        if(cnt >= C)
            lo = mid+1;
        else
            hi = mid-1;
    }

    cout << hi << endl;
}