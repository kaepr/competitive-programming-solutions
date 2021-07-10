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

ll powmod(ll x, ll y, ll mod)
{
    ll res = 1;
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

const ll MOD = 1e9 + 7;

void solve()
{
    ll n;
    cin>>n;
    ll grid[n][2];
    for(ll i=0; i<2; i++){
        for(ll j=0; j<n; j++){
            cin>>grid[j][i];
        }
    }

    map<ll,ll> mp1, mp2;
    for(ll i=0; i<n; i++){
        mp1[grid[i][0]] = grid[i][1];
        mp2[grid[i][1]] = grid[i][0];
        
    }

    for(ll i=0; i<n; i++){
        if(mp1[grid[i][0]] == mp2[grid[i][0]]){
           
        }
    }

    // trace(cnt);


    ll ans = 1;
    ll cnt = 0;
    ll vis[n] = {0};
    for(ll i=0; i<n; i++){
        if(vis[grid[i][0]- 1]==0){
            ll curr = grid[i][0];
            vis[curr-1] = 1;
            ll next = mp1[curr];
            while(curr!=next){
                vis[next - 1] = 1;
                next = mp1[next];

            }
            cnt++;
        }
    }
    
    cout<<powmod(2,cnt,MOD)<<"\n";
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