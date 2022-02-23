#include<bits/stdc++.h>

using namespace std;

int N, K;
deque<int> dq;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string tmp;

    cin >> N >> K;
    cin >> tmp;

    for(int i = 0; i < tmp.length(); ++i)
    {
        if(i == 0)
            dq.push_back(tmp[i] - '0');
        else
        {
            while(K && !dq.empty() && dq.back() < tmp[i]-'0')
            {
                K--;
                dq.pop_back();
            }
            dq.push_back(tmp[i] - '0');
        }
    }
    
    while(K)
    {
        K--;
        dq.pop_back();
    }

    for(int i : dq)
        cout << i;


    return 0;
}