#include<bits/stdc++.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int N;
vector<string> L;

// '1*' < '2*' < '3* < ... < '9*'
bool comp(string a, string b)
{
    if(a[0] != b[0])
        return a[0] < b[0];
    
    int alen = a.length();
    int blen = b.length();

    for(int i= 0; i < 10; ++i)
        if(a[i%alen] != b[i%blen])
            return a[i%alen] < b[i%blen];

    return a.length() < b.length();
}

int main(void)
{
    string tmp;
    string tmp2;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;

    for(int i = 0;i < N; ++i)
    {
        cin >> tmp;
        L.push_back(tmp);
    }

    sort(L.begin(), L.end(), comp);

    if((*L.rbegin())[0] == '0')
        cout << 0 << endl;
    else
    {
        for(vector<string>::reverse_iterator  i = L.rbegin(); i != L.rend(); ++i)
            cout << *i;
    }
    return 0;
}