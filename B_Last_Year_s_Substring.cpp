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
    string s;
    cin >> s;
    map<string, int> mp;
    string s1 = "2020";
    string s2 = "2";
    string s3 = "020";
    string s4 = "20";

    if (s == "2020")
    {
        cout << "YES\n";
        return;
    }

    if (s.substr(0, 4) == "2020")
    {
        cout << "YES\n";
        return;
    }

    if (s.substr(n - 4, 4) == "2020")
    {
        cout << "YES\n";
        return;
    }

    if (s.substr(0,1) == "2")
    {
        if (s.substr(n - 3, 3) == "020")
        {
            cout << "YES\n";
            return;
        }
    }

    if (s.substr(0, 2) == "20")
    {
        if (s.substr(n - 2, 2) == "20")
        {
            cout << "YES\n";
            return;
        }
    }

    if (s.substr(0, 3) == "202")
    {
        if (s.substr(n - 1, 1) == "0")
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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