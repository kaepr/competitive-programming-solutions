#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

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
    //use cerr if u want to display at the bottom
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

ll invCntCalc(vector<ll> a)
{
    ll cnt = 0;
    ll n = a.size();
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (a[i] > a[j] && j > i)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    vector<ll> a;
    ll ptr = 0;
    ll diff = n - k;
    ll sum = 0;
    // for (ll i = 1; i <= diff; i++)
    // {
    //     sum += i * (i + 1) / 2;
    // }
    ll invCnt = sum;
    for (ll i = ptr; i < k; i++)
    {
        a.PB(i + 1);
        ptr++;
    }

    // trace(ptr);
    ll val = ptr;
    while (ptr != n)
    {
        val--;
        a.PB(val);
        ptr++;
    }

    // cout << "THIS A\n";
    // for (auto x : a)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    diff++;
    //reverse last diff elements

    vector<ll> p;
    p.PB(0);
    for (int i = 0; i < k; i++)
    {
        p.PB(i + 1);
    }

    vector<ll> b;
    // trace(invCnt);
    // cout << "Inv Count = " << invCntCalc(a) << "\n";
    invCnt = invCntCalc(a);
    sort(p.begin(), p.end());
    p.erase(p.begin(), p.begin() + 1);

    ll pz = p.size();

    reverse(p.begin() + pz - diff, p.end());

    for (auto x : p)
    {
        cout << x << " ";
    }
    cout << "\n";

    // do
    // {
    //     cout << "CURRENT P\n";
    //     for (auto x : p)
    //     {
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    //     b.clear();
    //     for (ll i = 0; i < n; i++)
    //     {
    //         // trace(a[i]);
    //         // trace(p[a[i]]);
    //         b.PB(p[a[i]]);
    //     }
    //     if (invCntCalc(b) <= invCnt)
    //     {
    //         cout << "CURRENT B\n";
    //         for (auto x : b)
    //         {
    //             cout << x << " ";
    //         }
    //         cout << "\n";
    //         cout << "Inv Count = " << invCntCalc(b) << "\n";
    //     }

    // } while (next_permutation(p.begin(), p.end()));
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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