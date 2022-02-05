#include<bits/stdc++.h>

#define endl '\n'
#define isneg(num) (num < 0 ? 0 : num)

using namespace std;

int Memo[52][52][52];

int w(int a, int b, int c, int num)
{
    if(Memo[a][b][c])
        return Memo[a][b][c];
    
    if(!a || !b || !c)
        return Memo[a][b][c] = 1;

    if(a > 20 || b > 20 || c > 20)
        return Memo[a][b][c] = w(20, 20, 20, 0);
    
    if(a < b && b < c)
        return Memo[a][b][c] = w(a, b, c-1, 0) + w(a, b-1, c-1, 0) - w(a, b-1, c, 0);

    return Memo[a][b][c] = w(a-1, b, c, 0) + w(a-1, b-1, c, 0) + w(a-1, b, c-1, 0) - w(a-1, b-1, c-1, 0);
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int a, b, c;

    while(1)
    {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(isneg(a), isneg(b), isneg(c), 0) << endl;
    }
   
}