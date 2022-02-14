#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M;

int connected[100005];
int time_schedule[100005];
int find_parent(int idx)
{
    if (idx == connected[idx]) return idx;
    return connected[idx] = find_parent(connected[idx]);
}

void _union(int from, int to)
{
    int a = find_parent(to);
    int b = find_parent(from);

    connected[a] = b;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a, b;
    cin >> N >> M;

    for(int i = 1; i <= N; ++i)
        connected[i] = i;

    for(int i = 1; i <= M; ++i)
    {
        cin >> a >> b;
        _union(a, b);
    }

    for(int i = 1; i <= N; ++i)
        cin >> time_schedule[i];

    int ans = 0;
    int prev_building = find_parent(time_schedule[1]);
    for(int i = 2; i <= N; ++i)
    {
        int new_sub = find_parent(time_schedule[i]);
        if(prev_building != new_sub)
        {
            prev_building = new_sub;
            ans++;
        }
    }

    cout << ans << endl;
}