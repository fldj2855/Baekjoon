#include<bits/stdc++.h>
#define endl '\n'
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t, citation, tmp;
    int N;
    int Hindex;
    cin >> t;

    for(int i = 1; i <= t; ++i)
    {
        Hindex = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        cin >> N;

        cout << "Case #" << i << ": ";
        for(int j = 1; j <= N; ++j)
        {
            cin >> citation;

            if(citation > Hindex)
            {
                pq.push(citation);

                while(pq.top() <= Hindex)
                    pq.pop();
                
                Hindex = MAX(Hindex, pq.size());
            }
            
            cout << Hindex << " ";
        }

        cout << endl;
    }
    return 0;
}