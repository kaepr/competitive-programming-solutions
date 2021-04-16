#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const ll MOD = 1e9 + 7;

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

ll cntDigits(ll n)
{
    ll cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    // ll curr = cntDigits(n);
    map<ll, ll> mp;
    ll ans = 0;
    while (n > 0)
    {
        ll digit = n % 10;

        ll curr = 0;
        ll req_to_zero = 10 - digit;
        if (m < req_to_zero)
        {
            curr = 1;
        }
        else
        {
            // it will increase count atleast once
            // how many times it will increase is the question
            ll temp_m = m - req_to_zero;
            curr = 2;
            trace(temp_m);
            //now digit is at 10
            ll to_add = 1;
            ll times = temp_m / 10;
            while (times > 0)
            {
                to_add += to_add;
                times--;
            }
            // temp_m--;

            curr += to_add;
            curr %= MOD;
            // trace(times);
        }
        ans = (ans + curr) % MOD;
        ans %= MOD;
        n /= 10;
    }

    cout << (ans % MOD) << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll num = 12;
    ll temp = 100;
    while (temp > 0)
    {
        string res = "";
        while (num > 0)
        {
            ll digit = num % 10;
            digit++;
            res = res + to_string(digit);
            num /= 10;
        }
        trace(res);
        ll power = 1;
        num = 0;
        for (int i = res.length() - 1; i >= 0; i--)
        {
            num += power * (res[i] - '0');
            power *= 10;
        }
        // num = (ll)stoi(res);
        temp--;
    }

    // int t;
    // cin >> t;
    // while (t > 0)
    // {
    //     solve();
    //     t--;
    // }

    return 0;
}