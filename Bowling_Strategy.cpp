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
    int n, k, l;
    cin >> n >> k >> l;

    if(k==1 && n > 1){
        cout<<-1<<"\n";
        return;
    }
    if (n > k * l)
    {
        cout << -1 << "\n";
    }
    else
    {
        int ptr = 0;
        int bow = 1;
        while(ptr < n){
            if(bow > k){
                bow = 1;
            }
            cout<<bow<<" ";
            bow++;
            ptr++;
        }

        
        cout << "\n";
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}