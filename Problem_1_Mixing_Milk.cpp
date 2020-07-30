#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll c1, c2, c3, m1, m2, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    // cout << m1 << "\n"
    //      << m2 << "\n"
    //      << m3 << "\n";
    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        if (cnt % 3 == 0 || cnt == 0)
        {
            cnt = 0;
            int amt = min(m1, c2 - m2);
            m1 -= amt;
            m2 += amt;
            
        }
        else if (cnt == 1)
        {
            int amt = min(m2, c3 - m3);
            m2 -= amt;
            m3 += amt;
            
        }
        else if (cnt == 2)
        {
            int amt = min(m3, c1 - m1);
            m3 -= amt;
            m1 += amt;
        }
        //cout<<"m1 : "<<m1<<" m2 : "<<m2<<" m3 : "<<m3<<"\n";  

        cnt++;
    }
    cout << m1 << "\n"
         << m2 << "\n"
         << m3 << "\n";

    return 0;
}