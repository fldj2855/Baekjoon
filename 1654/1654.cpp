#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, K;
    ll ans = 0, c;
    ll lo, hi, mid;

    cin >> N >> K;

    vector<int> Lan(N);

    for(int i = 0; i < N; ++i)
        cin >> Lan[i];

    sort(Lan.begin(), Lan.end());
    lo = 1, hi = Lan[Lan.size()-1];    

    while(lo <= hi)
    {
        c = 0;
        mid = (lo + hi)/2;

        for(int i = 0; i < N; ++i)
            c += Lan[i]/mid;

        if(c >= K)
        {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }

        // cout << lo << " " << mid << " " << hi << endl;
    }

    cout << hi << endl;


    return 0;
}