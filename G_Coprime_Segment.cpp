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
void __f(const char *names, Arg1 &&arg1, Args &&...args)
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

struct custom_stack{
    vector<ll> s, sgcd = {0};

    void push(ll x){
        s.PB(x);
        ll elm = sgcd.back();
        sgcd.PB(__gcd(elm,x));
    }

    ll pop(){
        ll elm = s.back();
        s.pop_back();
        sgcd.pop_back();
        return elm;
    }

    ll ret_gcd(){
        return sgcd.back();
    }

    ll empty(){
        return s.empty();
    }
};

struct custom_stack s1,s2;

ll add(ll x){
    s2.push(x);
}

ll remove(){
    if(s1.empty()){
        while (!s2.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

bool good(){
    ll g1 = s1.ret_gcd();
    ll g2 = s2.ret_gcd();
    return __gcd(g1,g2)==1;
}

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 1e9;
    ll l = 0;
    for (ll r = 0; r < n; r++)
    {
        
    }

    if(ans==1e9){
        cout<<-1<<"\n";
    }else{
        cout<<ans<<"\n";
    }
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}