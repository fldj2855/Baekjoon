#include<bits/stdc++.h>

using namespace std;

int p[1005];

int main(void)
{
    int N, M;
    cin >> N >> M;

    for(int i =0; i < M; ++i)
        cin >> p[i];

    sort(p, p+M);

    size_t ans = 0, tmp;
    size_t save_i = 0;

    for(int i =0 ; i < N; ++i)
    {
        // p[i:] : someone who can buy p[i]
        // len(p[i:]) : how many people can buy p[i]
        
        tmp = min(N, (M-i))*p[i];
        cout << tmp << endl;
        if(ans < tmp)
        {
            save_i = p[i];
            ans= tmp;
        }
    }

    cout << save_i << " " << ans << endl;

    return 0;
}