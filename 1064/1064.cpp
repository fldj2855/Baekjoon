#include<bits/stdc++.h>
#define endl '\n'
#define INF 1000000007

using namespace std;

int main(void)
{
    cout.precision(15);

    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    double ans = -1.0;
    double d1 = 0.0, d2 = 0.0;
    double dy, dx;

    dy = (yb - ya);dx = (xb - xa);
    d1 = (dx == 0 ? INF : dy/dx);

    dy = (yc - yb);dx = (xc - xb);
    d2 = (dx == 0 ? INF : dy/dx);
    if(d1 == d2)
    {
        cout << "-1.0" << endl;
        return 0;
    }

    // check ab - cd
    double Len[4];
    double ab, ac, bc, bd;
    ab = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
    Len[0] = ab*2;
    Len[1] = ab*2;

    ac = sqrt((xc-xa)*(xc-xa) + (yc-ya)*(yc-ya));
    bc = sqrt((xc-xb)*(xc-xb) + (yc-yb)*(yc-yb));
    Len[0] += max(ac, bc)*2;
    Len[1] += min(ac, bc)*2;

    // check ac - bd
    ac = sqrt((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc));
    Len[2] = ac*2;
    Len[3] = ac*2;

    ab = sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
    bc = sqrt((xb-xc)*(xb-xc) + (yb-yc)*(yb-yc));
    Len[2] += max(ab, bc)*2;
    Len[3] += min(ab, bc)*2;

    sort(Len, Len+4);
    cout << Len[3] - Len[0] << endl;

    return 0;
}