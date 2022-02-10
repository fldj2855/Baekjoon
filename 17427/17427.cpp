#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    long long ret =0;
    for(int i = 1; i <= n; ++i)
        ret += i*(n/i);

    cout << ret << endl;
    

    return 0;
}