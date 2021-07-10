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

bool check(int num, int d)
{
    while (num > 0)
    {
        int dig = num % 10;
        if (dig == d)
            return true;
        num /= 10;
    }
    return false;
}

void solve()
{
    int q, d;
    cin >> q >> d;
    // trace(q, d);
    while (q > 0)
    {

        int n;
        cin >> n;
        // trace(n);
        if (n > 10 * d)
        {
            cout << "YES\n";
        }
        else if (d == 1)
        {
            cout << "YES\n";
        }
        else if (check(n, d))
        {
            cout << "YES\n";
        }
        else
        {
            bool flag = false;
            int num = d;

            for (int i = 1; i <= 10; i++)
            {
                num = i * d;
                if (check(n - num, d))
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        q--;
    }
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