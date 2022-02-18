#include<bits/stdc++.h>
#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    stack<pii> s;

    int N, tmp;
    cin >> N;

    s.push(pii(INF, 0));
    for(int i = 1; i <= N; ++i)
    {
        cin >> tmp;
        pii elem = pii(tmp, i);

        while(s.top().first < tmp)
            s.pop();
        
        cout << s.top().second << " ";
        s.push(elem);
    }

    return 0;
}