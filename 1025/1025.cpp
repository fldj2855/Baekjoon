#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

int board[11][11];
int N, M;
ll ans = -1;

int check_sqrt(ll num)
{
    ll a = (ll)sqrt(num);
    // cout << num << " " << a << " " << a*a << endl;
    return num == a*a;
}

void find_square(int y, int x, int dy, int dx, ll num)
{
    // 1 digit
    if(dy == 0 && dx == 0)
    {
        if(check_sqrt(num) && ans < num)
            ans = num;
        return;
    }

    // border check
    if(!(1 <= y + dy && y + dy <= N && 1 <= x + dx && x + dx <= M))
        return;
    
    num = num*10 + board[y+dy][x+dx];
    if(check_sqrt(num) && ans < num)
        ans = num;

    return find_square(y+dy, x+dx, dy, dx, num);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s;
    cin >> N >> M;

    for(int i = 1; i <= N; ++i)
    {
        cin >> s;
        for(int j = 1;j <= M; ++j)
        {
            // scanf("%1d", &board[i][j]); // DO NOT USE with `ios_base::sync_with_stdo(false)`
            board[i][j] = (ll)s[j-1] - '0';
        }
    }
    
    for(int i = 1; i <= N; ++i)
        for(int j = 1;j <= M; ++j)
            for(int dy = 1; dy <= N; ++dy)
                for(int dx = 1; dx <= M; ++dx)
                    find_square(i, j, dy-i, dx-j, board[i][j]);

    cout << ans << endl;
}