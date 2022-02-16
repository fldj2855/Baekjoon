#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    stack<int> H;
    stack<int> same;
    int N;

    cin >> N;

    long long a;
    long long ans =0 ;
    int same_value = 0;
    while(N--)
    {
        same_value = 1;
        cin >> a;

        assert(H.size() == same.size() && "assert 1");
        if(H.size() && H.top() == a)
        {
            same_value = same.top() + 1;
        }
        else if(H.size() && H.top() < a)
        {

            int prev_H = H.top();
            while(H.size() && H.top() < a)
            {
                int Loopcnt = same.top();

                if(H.top() >= prev_H)
                    ans += Loopcnt;

                while(Loopcnt--)
                {
                    H.pop();
                    same.pop();
                }
            }

            assert(H.size() == same.size() && "??");
            if(H.size() && H.top() == a)
            {
                same_value = same.top() + 1;
            }
        }

        // cout << a << " " << same_value << endl;
        H.push(a);
        same.push(same_value);
        if(H.size() == same_value)
        {
            ans += (H.size() ? same_value - 1 : 0);
        }
        else
            ans += (H.size() ? same_value : 0);

    }

    cout << ans << endl;

    return 0;
}