#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

char comp(char *a, char *b)
{
    char *p = a;
    char *q = b;

    while(*p && *q)
    {
        if(isdigit(*p) && isdigit(*q))
        {
            if(atoi(p) != atoi(q))
                return (atoi(p) <= atoi(q) ? '+' : '-');
        }
        
        if(*p != *q)
            return (*p <= *q ? '+' : '-');
        ++p;
        ++q;
    }

    return (*p == '\0' ? '+' : '-');
}

int main(void)
{
    int N;
    char p[10];
    char q[10];
    cin >> N;
    cin >> p;

    while(N--)
    {
        cin >> q;
        cout << comp(p, q) << endl;
    }
}