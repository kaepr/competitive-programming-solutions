#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define pb push_back
#define F first
#define S second
#define mp make_pair

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
    string s;
    cin >> s;
    // cout << stoi(s) << "\n";
    if (stoi(s) % 21 == 0)
    {
        cout << "The streak is broken!\n";
        return;
    }
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s.substr(i, 2) == "21")
        {
            cout << "The streak is broken!\n";
            return;
        }
    }
    cout << "The streak lives still in our heart!\n";
    // if (stoi(s))
    // {
    //     cout << "The streak is broken!\n";
    //     return;
    // }
    // else
    // {
    //     for (int i = 0; i < s.length(); i++)
    //     {
    //         if (stoi(s.substr(i)) % 21 == 0)
    //         {
    //             cout << "The streak is broken!\n";
    //             return;
    //         }
    //     }
    // }
    // cout << "The streak lives still in our heart!\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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