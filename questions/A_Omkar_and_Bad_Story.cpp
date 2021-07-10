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

vi make_nice(vi yes)
{
    vi ans;
    set<int> st;
    int n = yes.size();

    for (int i = 0; i < n; i++)
    {
        st.insert(yes[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int elm = abs(yes[i] - yes[j]);
                st.insert(elm);
            }
        }
    }

    for (auto x : st)
    {
        ans.PB(x);
    }

    return ans;
}

bool isNice(vi ans)
{
    int n = ans.size();
    map<int, int> mp;
    for (auto x : ans)
    {

        mp[x]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (mp.find(abs(ans[i] - ans[j])) == mp.end())
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;
    vi v;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.PB(x);
        st.insert(x);
    }
    bool f = false;
    int cnt = 0;
    while (true)
    {
        if (cnt > 10)
        {
            f = false;
            break;
        }
        vi newarr = make_nice(v);

        if (newarr == v)
        {
            if (isNice(newarr))
            {
                cout << "Yes\n";
                cout << newarr.size() << "\n";
                for (auto x : newarr)
                {
                    cout << x << " ";
                }
                cout << "\n";
                return;
            }
            else
            {
                cout << "No\n";
                return;
            }
        }

        if (newarr.size() <= 300)
        {
            if (isNice(newarr))
            {
                cout << "Yes\n";
                cout << newarr.size() << "\n";
                for (auto x : newarr)
                {
                    cout << x << " ";
                }
                cout << "\n";
                return;
            }
            else
            {
                v = newarr;
            }
        }
        else
        {
            f = false;
            break;
        }
        cnt++;
    }

    if (!f)
    {
        cout << "No\n";
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