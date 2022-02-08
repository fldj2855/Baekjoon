#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

map<string, int> menmap;
map<string, int> womenmap;
map<int, string> invwomenmap;

int T, N;
int men_prefer[202][202];
int men_tryidx[202];

int women_prefer[202][202];
int women_inv_prefer[202][202];

int women_match[202];
int men_match[202];

void match()
{
    queue<pii> manQ;

    for(int i = 1; i <= N; ++i)
    {
        // i'th man try 1( men_prefer )
        men_tryidx[i] += 1;
        manQ.push(pii(i, men_prefer[i][1])); 
    }

    while(!manQ.empty())
    {
        pii trying_man = manQ.front();
        manQ.pop();

        int man_idx = trying_man.first;
        int try_idx = trying_man.second;
        
        if(women_match[try_idx] == 0) // not match
        {
            men_match[man_idx] = try_idx;
            women_match[try_idx] = man_idx;
        }
        else if(women_inv_prefer[try_idx][women_match[try_idx]] 
                    < women_inv_prefer[try_idx][man_idx])
        {
            men_tryidx[man_idx]++;
            manQ.push(pii(man_idx, men_prefer[man_idx][men_tryidx[man_idx]]));
        }
        else if(women_inv_prefer[try_idx][women_match[try_idx]] 
                    > women_inv_prefer[try_idx][man_idx])
        {

            men_tryidx[women_match[try_idx]]++;
            men_match[women_match[try_idx]] = 0;

            manQ.push(pii(women_match[try_idx], 
                men_prefer[women_match[try_idx]][men_tryidx[women_match[try_idx]]]));

            men_match[man_idx] = try_idx;
            women_match[try_idx] = man_idx;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    string tmp, tmp2;
    for(int i = 1; i <= N; ++i)
    {
        cin >> tmp;
        menmap[tmp] = i;
    }
    for(int i = 1; i <= N; ++i)
    {
        cin >> tmp;
        womenmap[tmp] = i;
        invwomenmap[i] = tmp;
    }
    for(int i = 1; i <= N; ++i)
    {
        cin >> tmp2;
        for(int j = 1; j <= N; ++j)
        {
            cin >> tmp;
            men_prefer[menmap[tmp2]][j] = womenmap[tmp];
            // cin >> men_prefer[i][j];
        }
    }
    
    for(int i = 1; i <= N; ++i)
    {
        cin >> tmp2; // women
        for(int j = 1; j <= N; ++j)
        {
            cin >> tmp;
            
            women_prefer[womenmap[tmp2]][j] = menmap[tmp];
            women_inv_prefer[womenmap[tmp2]][menmap[tmp]] = j;

            // women_prefer[womenmap[tmp2]][j] = menmap[tmp];
            // women_inv_prefer[i][women_prefer[i][j]] = j;
        }
    }
    
    match();

    for(auto &it : menmap)
    {
        // cout << it.first << " " << it.second << endl;
        cout << it.first << " " << invwomenmap[men_match[it.second]] << endl;
    }

    return 0;
}