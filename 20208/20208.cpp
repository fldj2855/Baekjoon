#include<bits/stdc++.h>
#define MAX(a, b) ((a) > (b) ? a : b)
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

int N, M, H;
bool visited[10][10];
vector<pii> milk;

int sx, sy;
int ans;

void solve(int y, int x, int hp, int save)
{
    if(save > ans)
        if(hp >= abs(y-sy) + abs(x-sx))
            ans = save;

    if(ans == milk.size())
        return;
    
    for(vector<pii>::iterator i = milk.begin(); i != milk.end(); ++i)
    {
        int Y = (*i).first;
        int X = (*i).second;
        if(!visited[Y][X])
        {
            if(hp - abs(y-Y) - abs(x-X) < 0)
                continue;
                
            int new_hp = hp - abs(y-Y) - abs(x-X) + H;
            if(new_hp > 0)
            {
                visited[Y][X] = true;
                solve(Y, X, new_hp, save+1);
                visited[Y][X] = false;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M >> H;
    
    int tmp;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> tmp;
            if(tmp == 1)
                sy = i, sx=j;
            else if(tmp == 2)
                milk.push_back(pii(i, j));
        }
    }

    solve(sy, sx, M, 0);
    cout << ans << endl;

    return 0;
}