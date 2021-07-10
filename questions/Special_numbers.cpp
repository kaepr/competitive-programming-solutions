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

int p;

void solve()
{
    cin >> p;
    int n;
    cin >> n;
    // trace(p, n);
    while (n > 0)
    {
        int x;
        cin >> x;
        // trace(x);
        if (x == 1)
        {
            cout << "NO\n";
            // n--;
        }
        else
        {
            int totalTimes = 0;
            int num = 2;
            // bool flag = true;
            while (x > 1)
            {
                int copy = x;
                int cnt = 0;
                while (true)
                {
                    // if(copy )
                    if (x > 1 && x % num == 0)
                    {
                        cnt++;
                        x /= num;
                    }
                    else
                    {
                        break;
                    }
                }
                // trace(x);
                if (cnt > 0)
                {
                    totalTimes++;
                }
                num++;
                // totalTimes++;
                // x = x;
            }

            if (totalTimes >= p)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            // cout << "YES\n";
        }

        n--;
    }
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