#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mod = 1e9 + 7;

#define pb push_back
#define f first
#define s second
#define mp make_pair

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
    // vi v;
    // v.pb(1);
    // for(auto x : v){
    //     cout<<x<<"\n";
    // }
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    bool flag = false;
    sort(a,a+n);
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    if(sum==m){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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