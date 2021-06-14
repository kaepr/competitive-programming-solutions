#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

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

const int MOD = 1e9 + 7;

void solve()
{
    ll n;
    cin>>n;
    ll a[n],pre[n];
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }

    pre[0] = a[0];
    for(ll i=1; i<n; i++){
        pre[i] = a[i] ^ pre[i-1];
    }

    // for(ll i=0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";

    // for(ll i=0; i<n; i++){
    //     cout<<pre[i]<<" ";
    // }
    // cout<<"\n";

    if(pre[n-1]==0){
        cout<<"YES\n";
        return;
    }

    ll curr_xor = a[0];
    for(ll i=1; i<n; i++){
        ll mid_xor = a[i];
        for(ll j=i+1; j<n; j++){
            // trace(curr_xor, mid_xor, pre[n-1]);
            if(curr_xor==mid_xor && curr_xor == pre[n-1]){
                cout<<"YES\n";
                return;
            }
            mid_xor ^= a[j];
        }
        curr_xor ^= a[i];
    }

    cout<<"NO\n";




}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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