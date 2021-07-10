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

void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        a.PB(x);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    // for (auto x : a)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    int elm1 = a[0];
    vector<pair<int, int>> v;
    int X;
    for (int i = 1; i < 2 * n; i++)
    {
        v.clear();
        //chosen as second elm
        int elm2 = a[i];
        v.PB(MP(a[0], a[i]));
        int x = max(elm1, elm2);
        X = elm1 + elm2;
        multiset<int> mts;
        for (int j = 0; j < 2 * n; j++)
        {
            if (i != j && j != 0)
            {
                mts.insert(a[j]);
            }
        }
        // trace(x, elm1, elm2);
        // for (auto val : mts)
        // {
        //     cout << val << " ";
        // }
        // cout << "\n";
        int ptr = n - 1;
        while (ptr >= 0)
        {
            if ((int)v.size() == n)
            {
                cout << "YES\n";
                cout << X << "\n";
                for (auto x : v)
                {
                    cout << x.first << " " << x.second << "\n";
                }
                return;
            }

            auto it1 = mts.end();
            it1--;

            int val1 = *it1;
            mts.erase(it1);
            // trace(x, val1);
            int val2 = x - val1;
            auto it2 = mts.find(val2);

            if (it2 == mts.end())
            {
                // cout << "BREAKK\n";
                break;
            }
            else
            {
                x = max(val1, val2);
                mts.erase(it2);
                v.PB(MP(val1, val2));
            }

            // trace(val1, val2);

            // if (mts.find(x - val1) != mts.end())
            // {
            //     v.PB(MP(val1, x - val1));
            //     x = max(val1, x - val1);
            //     mts.erase(mts.find(x - val1));
            // }
            // else
            // {
            //     break;
            // }
            ptr--;
        }
    }
    cout << "NO\n";
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