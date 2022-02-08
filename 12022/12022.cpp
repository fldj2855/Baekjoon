#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;


int T, N;
int men_prefer[1002][1002];
int men_tryidx[1002];

int women_prefer[1002][1002];
int women_inv_prefer[1002][1002];

int women_match[1002];
int men_match[1002];

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
    
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            cin >> men_prefer[i][j];
    
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            cin >> women_prefer[i][j];
            women_inv_prefer[i][women_prefer[i][j]] = j;
        }
    }
    
    match();

    for(int i = 1; i <= N; ++i)
    {
        cout << men_match[i] << endl;
    }

    return 0;
}