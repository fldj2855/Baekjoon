#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<string> v;

bool compare(string a, string b) {
    int i = 0;
    if(a.length() == b.length())
    {
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] != b[i])
                return a[i] < b[i];
        }
    }
    return a.length() < b.length();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tmp;
    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), compare);
    
    vector<string>::iterator i;

    cout << v[0] << endl;
    for(int i = 1; i < v.size(); ++i)
    {
        if(v[i] != v[i-1])
            cout << v[i]  << endl;
    }
    return 0;
}