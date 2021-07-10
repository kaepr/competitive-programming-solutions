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
    string str;
    cin >> str;
    int n = str.length();
    bool abFlag = false, baFlag = false;

    vi f, s;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == 'A' && str[i + 1] == 'B')
            f.PB(i);

        if (str[i] == 'B' && str[i + 1] == 'A')
            s.PB(i);
    }

    if (f.empty() || s.empty())
    {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < f.size(); i++)
    {
        int pos = f[i];
        //AB starts at pos
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] != pos && s[j] + 1 != pos && s[j] != pos + 1 && s[j] + 1 != pos)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        int pos = s[i];
        //AB starts at pos
        for (int j = 0; j < f.size(); j++)
        {
            if (f[j] != pos && f[j] + 1 != pos && f[j] != pos + 1 && f[j] + 1 != pos)
            {
                cout << "YES\n";
                return;
            }
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

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}