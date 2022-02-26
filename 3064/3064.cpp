#include<bits/stdc++.h>
#define endl '\n'
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

int mine[105][105];
int dxy[8][2] = {
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1}
};

void printing(int N)
{
    for(int i =0 ; i < N+2; ++i)
    {
        for(int j = 0; j < N+2; ++j)
        {
            cout << (mine[i][j] == '*'? '*' : '.') << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void find(int y, int x)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        if (mine[x + dxy[i][0]][y + dxy[i][1]] == '*')
            cnt++;
    }
    if (cnt == mine[x][y]) {
        for (int i = 0; i < 8; i++) {
            if (mine[x + dxy[i][0]][y + dxy[i][1]] == '#')
                mine[x + dxy[i][0]][y + dxy[i][1]] = '.';
        }
    }
    else {
        for (int i = 0; i < 8; i++) {
            if (mine[x + dxy[i][0]][y + dxy[i][1]] == '#')
                mine[x + dxy[i][0]][y + dxy[i][1]] = '*';
        }
    }

}


int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T, N;
    cin >> T;
    while(T--)
    {
        memset(mine, 0, sizeof(mine));
        cin >> N;
        
        for(int i = 1; i <= N; ++i)
        {
            string tmp;
            cin >> tmp;
            for(int j = 0; j < N; ++j)
            {
                if(isdigit(tmp[j]))
                {
                    mine[i][j+1] = tmp[j] - '0';
                }
                else
                {
                    mine[i][j+1] = tmp[j];
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            find(1, i);
        }
        for (int i = 2; i <= N; i++) {
            find(i, N);
        }
        for (int i = N - 1; i >= 1; i--) {
            find(N, i);
        }
        for (int i = N - 1; i > 1; i--) {
            find(i, 1);
        }

        // printing(N);
        int ans = 0;
        for(int i = 1; i < N+1; ++i)
        {
            for(int j = 1; j < N+1; ++j)
            {
                ans += (mine[i][j] == '*' || mine[i][j] == '#');
            }
        }
        cout << ans << endl;
    }
    return 0;
}