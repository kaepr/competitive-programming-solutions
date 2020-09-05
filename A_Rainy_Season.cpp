#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve()
{
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    if(s=="RRR")
        cout<<3<<"\n";
    else if(s=="RRS" || s=="SRR")
        cout<<2<<"\n";
    else if(s=="SRS" || s=="SSR" || s=="RSS" || s=="RSR")
        cout<<1<<"\n";
    else
        cout<<0<<"\n";

    return 0;
}