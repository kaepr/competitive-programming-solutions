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
    int n;
    cin >> n;
    vi a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.PB(x);
    }
    vector<vector<int>> ans;
    int max_val = *max_element(a.begin(), a.end());
    int rem = n - max_val;
    set<int> st;
    int curr_max = 0;
    for (int i = 0; i < max_val; i++)
    {
        curr_max = max(curr_max, a[i]);
        st.insert(a[i]);
    }

    set<int> st2;
    int curr_max_2 = 0;
    for (int i = max_val; i < n; i++)
    {
        curr_max_2 = max(curr_max_2, a[i]);
        st2.insert(a[i]);
    }

    if (st.size() == max_val && st2.size() == rem)
    {
        if (curr_max == max_val && curr_max_2 == rem)
        {
            vi tmp;
            tmp.PB(max_val);
            tmp.PB(rem);
            ans.PB(tmp);
        }
    }

    max_val = *max_element(a.begin(), a.end());
    rem = n - max_val;
    st.clear();
    st2.clear();
    curr_max = 0;
    for (int i = 0; i < rem; i++)
    {
        curr_max = max(curr_max, a[i]);
        st.insert(a[i]);
    }

    curr_max_2 = 0;
    for (int i = rem; i < n; i++)
    {
        curr_max_2 = max(curr_max_2, a[i]);
        st2.insert(a[i]);
    }

    if (st.size() == rem && st2.size() == max_val)
    {
        if (curr_max == rem && curr_max_2 == max_val)
        {
            vi tmp;
            tmp.PB(rem);
            tmp.PB(max_val);
            if (ans.size() == 0)
            {
                ans.PB(tmp);
            }
            else if (ans.size() == 1 && ans[0] != tmp)
            {
                ans.PB(tmp);
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
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