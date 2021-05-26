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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v;
    bool f = true;
    ll cnt_zero = 0, cnt_neg = 0, cnt_pos = 0;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x <= 0)
        {
            f = false;
        }

        if (x < 0)
        {
            cnt_neg++;
        }
        else if (x > 0)
        {
            cnt_pos++;
        }
        else if (x == 0)
        {
            cnt_zero++;
        }
        mp[x]++;
        v.PB(x);
    }

    if (cnt_pos > 0 && cnt_neg == 0 && cnt_zero == 0)
    {
        cout << 1 << "\n";
    }
    else if (cnt_neg > 0 && cnt_pos == 0 && cnt_zero == 0)
    {
        cout << cnt_neg << "\n";
    }
    else if (cnt_zero > 0 && cnt_pos == 0 && cnt_neg == 0)
    {
        cout << cnt_zero << "\n";
    }
    else if (cnt_pos > 0 && cnt_neg > 0 && cnt_zero == 0)
    {
        cout << cnt_neg + 1 << "\n";
    }
    else if (cnt_pos > 0 && cnt_zero > 0 && cnt_neg == 0)
    {
        cout << max(cnt_zero, (ll)2) << "\n";
    }
    else if (cnt_neg > 0 && cnt_zero > 0 && cnt_pos == 0)
    {
        cout << cnt_neg + cnt_zero << "\n";
    }
    else if (cnt_pos > 0 && cnt_neg > 0 && cnt_zero > 0)
    {

        ll cnt = 0;
        ll ans = 0;
        ll lastElm = 0;
        for (auto x : mp)
        {
            if (cnt == 0)
            {
                lastElm = x.first;
                ans++;
            }
            else
            {
                if (lastElm > 0)
                {
                    break;
                }
                ans++;
                lastElm = x.first;
            }

            cnt++;
        }
        // cout << "here\n";
        // trace(cnt_pos, cnt_neg, cnt_zero);
        // trace(ans);
        cout << ans << "\n";
        // cout << max((ll)2 + cnt_pos - 1, cnt_zero + cnt_neg) << "\n";
    }

    //     ll largest = *max_element(v.begin(), v.end());

    // if (largest < 0)
    // {
    //     cout << n << "\n";
    //     return;
    // }

    // if (largest == 0 && !f)
    // {
    //     cout << n << "\n";
    //     return;
    // }

    // if (f)
    // {
    //     cout << 1 << "\n";
    //     return;
    // }

    // if (cnt_zero > 0)
    // {
    //     cnt_zero = 1;
    // }

    // cout << cnt_zero + cnt_neg + 1 << "\n";
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