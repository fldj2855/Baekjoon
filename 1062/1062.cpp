#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

// a c i n t
map<char, size_t> key = {
    {'b',1<<0}, {'d',1<<1}, {'e',1<<2}, {'f',1<<3}, {'g',1<<4}, {'h',1<<5}, {'j',1<<6}, {'k',1<<7}, {'l',1<<8}, {'m',1<<9}, {'o',1<<10}, {'p',1<<11}, {'q',1<<12}, {'r',1<<13}, {'s',1<<14}, {'u',1<<15}, {'v',1<<16}, {'w',1<<17}, {'x',1<<18}, {'y',1<<19}, {'z',1<<20}
};
vector<char> v = {'b','d','e','f','g','h','j','k','l','m','o','p','q','r','s','u','v','w','x','y','z'};
vector<bool> b(v.size());
vector<size_t> wordlist;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    char word[16];
    cin >> N >> K;
    if(K < 5)
    {
        cout << 0 << endl;
        return 0;
    }
    size_t word_sum;

    for(int i = 0; i < N; ++i)
    {
        word_sum = 0;
        cin >> word;
        
        int len = strlen(word);
        for(int j = 0; j < len; ++j)
        {
            if(word[j] == 'a' || word[j] == 'c' || word[j] == 'i' || word[j] == 'n' || word[j] == 't')
                continue;
            
            word_sum |= key.at(word[j]);
        }
        
        wordlist.push_back(word_sum);
    }  
    
    // set combination bits
    for(int i = 0; i < K-5; ++i)
        b[i] = true;
    
    sort(b.begin(), b.end());

    // combination using permutation
    size_t MAX_CNT = 0;
    size_t cnt;
    size_t combination_word_sum;
    do{
        // cout << "===================" << endl;
        cnt = 0;
        combination_word_sum = 0;

        // calc combination alphabet bits
        for(int i = 0; i < v.size(); ++i)
        {
            if(b[i])
                combination_word_sum |= key.at(v[i]);
        }

        // compare word_list
        for(int i = 0; i < N; ++i)
        {
            if((wordlist[i] & combination_word_sum) == wordlist[i] )
                cnt++;
        }

        if(MAX_CNT < cnt)
            MAX_CNT = cnt;

    }while(next_permutation(b.begin(), b.end()));

    cout << MAX_CNT << endl;

    return 0;
}