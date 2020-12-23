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
    string s, t;
    cin >> s >> t;
    // if (s == t)
    // {
    //     cout << 0 << "\n";
    //     return;
    // }
    int cnta = 0, cntb = 0;
    vector<int> posab, posba;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            cnta++;
        else if (s[i] == 'b')
            cntb++;

        if (t[i] == 'a')
            cnta++;
        else if (t[i] == 'b')
            cntb++;

        if (s[i] == 'a' && t[i] == 'b')
        {
            posab.PB(i);
        }

        if (s[i] == 'b' && t[i] == 'a')
        {
            posba.PB(i);
        }
    }

    vector<pair<int, int>> ans;

    if ((posab.size() + posba.size()) % 2 != 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        if (posab.size() != 0)
        {
            for (int i = 0; i < posab.size() - 1; i += 2)
            {
                ans.PB(MP(posab[i], posab[i + 1]));
            }
        }

        if (posba.size() != 0)
        {
            for (int i = 0; i < posba.size() - 1; i += 2)
            {
                ans.PB(MP(posba[i], posba[i + 1]));
            }
        }

        if (posab.size() % 2 != 0 && posba.size() % 2 != 0)
        {
            ans.PB(MP(posab[posab.size() - 1], posab[posab.size() - 1]));
            ans.PB(MP(posab[posab.size() - 1], posba[posba.size() - 1]));
        }

        if (posab.size() != 0 && posba.size() != 0)
        {
        }

        cout << ans.size() << "\n";
        for (auto x : ans)
        {
            cout << x.first + 1 << " " << x.second + 1 << "\n";
        }
    }

    // if (cnta % 2 == 0 && cntb % 2 == 0)
    // {
    // }
    // else
    // {
    //     cout << -1 << "\n";
    // }
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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