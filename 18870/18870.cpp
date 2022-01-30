#include<bits/stdc++.h>

using namespace std;

vector<int> v, cv;

int main(void)
{
    int N;
    scanf("%d", &N);

    v.resize(N);

    for(int i =0 ; i < N; ++i)
    {
        scanf("%d", &v[i]);
    }

    cv.assign(v.begin(), v.end());
    sort(cv.begin(), cv.end());

    cv.erase(unique(cv.begin(), cv.end()), cv.end());

    for(int i = 0; i < N; ++i)
    {
        printf("%ld ", lower_bound(cv.begin(), cv.end(), v[i]) - cv.begin());
    }


    return 0;
}