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

ll find_max(multiset<ll> &st)
{
    if (!st.empty())
    {
        return *(st.rbegin());
    }
    return -1e18;
}

ll find_min(multiset<ll> &st)
{
    if (!st.empty())
    {
        return *(st.begin());
    }
    return 1e18;
}

struct custom_stack{
    vector<ll> s, smin={LLONG_MAX},smax={LLONG_MIN};

    void push(ll x){
        s.PB(x);

        ll x1 = smin.back();
        smin.PB(min(x1,x));
        x1 = smax.back();
        smax.PB(max(x1,x));
    }

    ll pop(){
        smin.pop_back();
        smax.pop_back();
        ll ret = s.back();
        s.pop_back();
        return ret;
    }

    bool empty(){
        return s.empty();
    }

    ll cur_min(){
        return smin.back();
    }

    ll cur_max(){
        return smax.back();
    }
};

struct custom_stack s1, s2;

void add(ll x){
    s2.push(x);   
}

void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

ll n,k,ans=0;

bool good(){
    ll mx = max(s1.cur_max(), s2.cur_max());
    ll mn = min(s1.cur_min(), s2.cur_min());

    if(mx - mn > k){
        return false;
    }else{
        return true;
    }
}

void solve()
{
    cin >> n >> k;
    ll arr[n];

    
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // vi v = {1,2,3,4,5};

    // cout<<v.back()<<"\n";

    ll l = 0;
    for(ll r=0; r<n; r++){
        add(arr[r]);
        while(!good()){
            remove();
            l++;
        }
        if(good()){
             ans += r - l + 1;
        }
       
    }

    cout<<ans<<"\n";

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