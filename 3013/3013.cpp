#include<bits/stdc++.h>
using namespace std;

int L[100002];

map<int, int> lgap;
map<int, int> rgap;

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, mid, offset;
    int a;
    int mididx = 0;
    
    cin >> N >> mid;

    for(int i = 0; i < N; ++i)
    {
        cin >> a;
        L[i] = a;
        if( a == mid )
            mididx = i;
    }

    if(N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    lgap[0] = rgap[0] = 1;

    offset = 0;
    for(int i = mididx-1; i >= 0; --i)
    {
        if(L[i] < mid) offset -= 1;
        else offset += 1;
        
        lgap[offset] += 1;
    }

    offset = 0;
    for(int i = mididx+1; i < N; ++i)
    {
        if(L[i] < mid) offset -= 1;
        else offset += 1;
        
        rgap[offset] += 1;
    }

    map<int,int>::iterator li = lgap.begin();
    map<int,int>::iterator ri = rgap.begin();
    
    // for(map<int,int>::iterator i = lgap.begin(); i != lgap.end(); ++i)
    //     cout << (*i).first << " " << (*i).second << endl;
    
    // cout << endl;
    // for(map<int,int>::iterator i = rgap.begin(); i != rgap.end(); ++i)
    //     cout << (*i).first << " " << (*i).second << endl;

    // cout << endl;

    int ans = 0;
    while(li != lgap.end())
    {
        // cout << (*li).second << " " << rgap[-(*li).first] << endl;
        ans += (*li).second * rgap[-(*li).first];
        
        li++;
        ri++;
    }

    cout << ans<< endl;
    return 0;
}