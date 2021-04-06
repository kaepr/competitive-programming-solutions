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

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "YES\n";
        return;
    }

    vi diff;
    int cnt[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cnt[i]++;
            diff.PB(i);
            // if (i % 2 == 1)
            // {
            // diff.PB(i);
            // }
        }
    }

    int zero_cnt = 0, one_cnt = 0, diff_ptr = 0;
    int dsz = diff.size();
    int lastElm = diff[dsz - 1];

    bool changed = false;

    vi poss;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
        {
            zero_cnt++;
        }
        else
        {
            one_cnt++;
        }
        if (one_cnt == zero_cnt)
        {
            poss.PB(i);
            mp[i]++;
        }
    }

    int need[n] = {0};
    int ptr11 = 0;
    for (auto x : diff)
    {
        need[x] = 1;
    }

    int curr_cnt = 0;
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (need[i] == 1)
        {
            if (curr_cnt == 0)
            {
                //needs changing, checking if elmements before can be changed back
                if (mp[i - 1] > 0)
                {
                    //cool we can change prev elementes
                }
                else
                {
                    if (i != 0)
                    {
                        // trace(i);
                        f = false;
                    }
                }
            }

            curr_cnt++;
            if (curr_cnt)
            {
                //only first elm, lets check more
            }
        }
        else
        {
            if (curr_cnt > 0)
            {
                if (mp[i - 1] > 0)
                {
                    //cool can change
                }
                else
                {
                    if (i != 0)
                    {
                        // trace(i);
                        f = false;
                    }
                }
            }
            curr_cnt = 0;
        }
    }

    if (curr_cnt > 0)
    {
        if (mp[n - 1] > 0)
        {
            //cool can change
        }
        else
        {
            // trace(n - 1);
            f = false;
        }
    }

    if (f)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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