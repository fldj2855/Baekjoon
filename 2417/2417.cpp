#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef unsigned long long ull;

int main(void)
{
    ull lo = 0;
    ull hi = 3037000500;
    ull mid, save = -1;
    ull n;
    cin >> n;    
    if(!n)
    {
        cout << 0 << endl;
        return 0;
    }

    while(lo <= hi)
    {
        mid = (lo + hi)/2;
        if(mid * mid >= n)
        {
            hi = mid - 1;
            if(save > mid) 
                save = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << save << endl;
    return 0;
}