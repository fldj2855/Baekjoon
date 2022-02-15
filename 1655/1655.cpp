#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T, N, mid, t;
    cin >> T;

    priority_queue<int, vector<int>, less<int>> MAX_HEAP;
    priority_queue<int, vector<int>, greater<int>> MIN_HEAP;

    // MIN_HEAP[MID] | MAX_HEAP
    while(T--)
    {
        cin >> t;
        if(MIN_HEAP.empty())
            MIN_HEAP.push(t);
        else if(MAX_HEAP.empty())
        {
            MIN_HEAP.push(t);
            MAX_HEAP.push(MIN_HEAP.top());
            MIN_HEAP.pop();
        }
        else
        {
            if(MAX_HEAP.size() - MIN_HEAP.size() == 0)
            {
                if(t < MIN_HEAP.top())
                {
                    MAX_HEAP.push(t);
                    MIN_HEAP.push(MAX_HEAP.top());
                    MAX_HEAP.pop();
                } else{
                    MIN_HEAP.push(t);
                }
            } else { // MAX > MIN
                assert(MIN_HEAP.size() > MAX_HEAP.size());

                MIN_HEAP.push(t);
                MAX_HEAP.push(MIN_HEAP.top());
                MIN_HEAP.pop();
            }
        }

        if( MAX_HEAP.size() == MIN_HEAP.size())
            cout << MAX_HEAP.top() << endl;
        else
            cout << MIN_HEAP.top() << endl;
    }
}