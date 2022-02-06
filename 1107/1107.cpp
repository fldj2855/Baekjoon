#include<bits/stdc++.h>
#define endl '\n'

using namespace std;


typedef struct cmd{
    int chan;
    int cnt;
    bool button_flag;
}cmd;

int button[] = {1,1,1,1,1,1,1,1,1,1};
bool visited[1000001][2]; // [0] : button & [1] : move

int BFS(int c)
{
    int ch;
    queue<cmd> q;

    q.push({100, 0, 0});
    for(int i = 0; i <= 9; ++i)
    {
        if(button[i])
        {
            q.push({i, 1, 1});
            visited[i][0] = true;
        }
    }
    
    visited[100][1] = true;

    while(!q.empty())
    {
        cmd tmp = q.front();
        q.pop();

        visited[tmp.chan][1] = true;

        // cout << tmp.chan << " " << tmp.cnt << " " << tmp.button_flag << endl;
        if(tmp.chan == c)
            return tmp.cnt;

        for(int i = 0; tmp.button_flag && i <= 9; ++i)
        {
            if(button[i])
            {
                ch = tmp.chan*10 + i;
                if(ch > 999999)
                    continue;

                if(!visited[ch][0])
                {
                    q.push({ch, tmp.cnt+1, 1});
                    visited[ch][0] = true;
                }
            }
        }

        if(tmp.chan+1 <= 999999 && !visited[tmp.chan+1][1])
        {
            visited[tmp.chan+1][1] = true;
            q.push({tmp.chan+1, tmp.cnt+1, 0});
        }
        
        if(tmp.chan-1 >= 0 && !visited[tmp.chan-1][1])
        {
            visited[tmp.chan-1][1] = true;
            q.push({tmp.chan-1, tmp.cnt+1, 0});
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M, c;
    cin >> N;

    cin >> M;

    for(int i = 0; i < M; ++i)
    {
        cin >> c;
        button[c] = 0;
    }

    cout << BFS(N) << endl;
    return 0;
}