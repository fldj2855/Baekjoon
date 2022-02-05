#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

bool dec_compare(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, s[100];
    int odd[100], oddlen = 0, even[100], evenlen = 0;
    cin >> T;

    for(int t = 1; t <= T; ++t)
    {
        oddlen = 0;
        evenlen = 0;
        
        cin >> N;
        for(int i = 0; i < N; ++i)
        {
            cin >> s[i];
            if(s[i] % 2)
                odd[oddlen++] = s[i];
            else
                even[evenlen++] = s[i];
        }
        
        sort(odd, odd + oddlen);
        sort(even, even + evenlen, dec_compare);
        
        for(int i = 0, ol = 0, el = 0; i < N; ++i)
        {
            if(s[i] % 2)
                s[i] = odd[ol++];
            else
                s[i] = even[el++];
        }
        
        cout << "Case #" << t << ": ";
        for(int i = 0; i < N; ++i)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
}