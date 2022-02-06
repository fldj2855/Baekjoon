#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int N, L, ans = 0;

    vector<int> v;

    cin >> N >> L;

    v.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    int start, i = 0;
    
    while(i < v.size())
    {
        ans++;start = v[i];
        while(i < v.size() && v[i] <= start + L - 1)
            ++i;
    }
    
    cout << ans << endl;

    return 0;
}