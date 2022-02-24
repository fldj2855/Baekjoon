#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M;
int numlist[8];

int arr[8];

bool isuse[8];

void NM(int k)
{
    if(k == M)
    {
        for(int i = 0; i < k; ++i)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    
    int last = 0;
    for(int i = 0; i < N; ++i)
    {
        if(!isuse[i] && numlist[i] != last)
        {
            arr[k] = numlist[i];
            last = arr[k];
            isuse[i] = true;
            NM(k+1);
            isuse[i] = false;
        }
    }
}

int main(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        cin >> numlist[i];
    
    sort(numlist, numlist+N);

    NM(0);

    return 0;
}