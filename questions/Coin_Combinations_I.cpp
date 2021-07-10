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
const int MAXN = 1e6 + 5;

int arr[MAXN];

int calc(int ptr, int sum){
    
    if(ptr < 0){
        return 0;
    }

    if(sum==0){
        return 1;
    }
    

    int ans = 0;
    if(arr[ptr]<=sum){
        ans = (ans + calc(ptr, sum - arr[ptr]) % MOD) % MOD;
        ans = (ans + calc(ptr - 1, sum) % MOD) % MOD;
        ans = (ans + calc(ptr - 1, sum - arr[ptr]) % MOD) % MOD;
    }else{
        ans =  calc(ptr-1, sum)% MOD;
    }
    return ans;
}

void solve()
{
    int n,x;
    cin>>n>>x;
    // int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // cout<<calc(n-1, x)<<"\n";
    int dp[n+1][x+1];
    memset(dp,0,sizeof(dp));

    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            int ans = 0;

            if(x > arr[i-1]){
                ans = (ans + dp[i-1][j] % MOD) % MOD;
                ans = (ans + dp[i-1][j - arr[i-1]] % MOD) % MOD;
            }else{
                ans = dp[i-1][j];
            }
            // trace(i,j,ans);
            dp[i][j] = ans;
        }
    }

     for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
           cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<dp[n][x]<<"\n";

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