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
    string s, t;
    cin >> s >> t;
    int slen = s.length(), tlen = t.length();

    // s -> t
    if (tlen > slen)
    {
        cout << "need tree\n";
        return;
    }

    map<char, int> smp, tmp;
    for (int i = 0; i < tlen; i++)
    {
        tmp[t[i]]++;
    }

    for (int i = 0; i < slen; i++)
    {
        smp[s[i]]++;
    }

    int vis[tlen];
    memset(vis, 0, sizeof(vis));

    int tptr = 0, sptr = 0;
    while (sptr < slen)
    {
        if (s[sptr] == t[tptr])
        {
            vis[tptr] = 1;
            tptr++;
            sptr++;
        }
        else
        {
            sptr++;
        }
    }

    bool f2 = true;
    for (auto x : tmp)
    {
        if (smp[x.F] < x.S)
        {
            f2 = false;
            break;
        }
    }

    if (!f2)
    {
        cout << "need tree\n";
        return;
    }

    bool f1 = true;
    for (int i = 0; i < tlen; i++)
    {
        if (!vis[i])
        {
            f1 = false;
        }
    }

    if (f1)
    {
        cout << "automaton\n";
    }
    else
    {
        bool f3 = true;
        for (auto x : tmp)
        {
            if (smp[x.F] != x.S)
            {
                f3 = false;
                break;
            }
        }

        if (f3 && smp.size() == tmp.size())
        {
            cout << "array\n";
        }
        else
        {
            cout << "both\n";
        }
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