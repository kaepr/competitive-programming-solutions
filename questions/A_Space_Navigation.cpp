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

string s;

void solve2(int x, int y)
{
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    // string s;
    cin >> s;

    ll left = 0, right = 0, up = 0, down = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == 'U')
        {
            up++;
        }
        else if (s[i] == 'D')
        {
            down++;
        }
        else if (s[i] == 'L')
        {
            left++;
        }
        else if (s[i] == 'R')
        {
            right++;
        }
    }

    if (y >= 0)
    {
        if (x >= 0)
        {
            //up right
            if ((right >= abs(x) && up >= abs(y)))
            {
                cout << "YES\n";
                return;
            }
        }
        else
        {
            //up left
            if ((left >= abs(x) && up >= abs(y)))
            {
                cout << "YES\n";
                return;
            }
        }
    }
    else
    {
        if (x >= 0)
        {
            if ((right >= abs(x) && down >= abs(y)))
            {
                cout << "YES\n";
                return;
            }
        }
        else
        {
            if ((left >= abs(x) && down >= abs(y)))
            {
                cout << "YES\n";
                return;
            }
        }
    }

    if (x >= 0)
    {
        if (y >= 0)
        {
            //up right
            if ((right >= abs(x) && up >= abs(y)))
            {
                cout << "YES\n";
                return;
            }
        }
        else
        {
            //up left
            if ((right >= abs(x) && down >= abs(y)))
            {
                cout << "YES\n";
                return;
            }
        }
    }
    else
    {
        if (y >= 0)
        {
            if ((left >= abs(x) && up >= abs(y)))
            {
                cout << "YES\n";
                return;
            }
        }
        else
        {
            if ((left >= abs(x) && down >= abs(y)))
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

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}