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

void solve()
{
    ll n, k;
    cin >> n >> k;

    if (n % 2 == 0)
    {
        if (k <= n)
        {
            cout << k << "\n";
        }
        else
        {
            if (k % n == 0)
            {
                cout << n << "\n";
            }
            else
            {
                cout << k % n << "\n";
            }
        }
    }
    else
    {
        // trace(n, k);
        ll temp = n / 2;
        // trace(n / 2);
        // temp++;
        // trace(temp);

        ll div = k / (temp);
        if (k % (temp) == 0)
            div--;
        ll change = k % (temp);
        if (change == 0)
        {
            change = temp;
        }
        // trace(div, change);
        ll ind = (div * (temp + 1)) % n;
        // trace(ind);
        // if (k == change)
        // {
        //     change = 0;
        // }
        // else
        // {
        // }
        // trace(ind);
        // if (ind == 0)
        // {
        //     ind++;
        // }
        // if (ind == 0)
        //     ind = n;
        // trace(ind, change);
        // if (change == 0)
        //     change--;
        int ans = (ind + change) % n;
        if (ans == 0)
        {
            cout << n << "\n";
        }
        else
        {
            cout << ans << "\n";
        }
        // trace(ans);
        // cout
        // << (ind + change) % n << "\n";

        // ind++;
        // if (ind == 0)
        // {
        // }

        // if (k >= n)
        // {
        // }

        // ll div = (k / (n / 2)) % n;
        // ll md = k % n;
        // cout << div * (n / 2) + md << "\n";

        // vi pattern;
        // int ptr1 = n, ptr2 = 1;
        // int times = n * 2;
        // trace(n, k);
        // while (times > 0)
        // {
        //     //ptr1 goes down
        //     //ptr2 goes up
        //     if (ptr1 == ptr2)
        //     {
        //         trace(ptr1, ptr2);
        //         //equal, so adjust ptr2
        //         if (ptr2 == n)
        //         {
        //             ptr2 = 1;
        //         }
        //         else
        //         {
        //             ptr2++;
        //         }

        //         pattern.PB(ptr2);

        //         if (ptr1 == 1)
        //         {
        //             ptr1 = n;
        //         }
        //         else
        //         {
        //             ptr1--;
        //         }

        //         if (ptr2 == n)
        //         {
        //             ptr2 = 1;
        //         }
        //         else
        //         {
        //             ptr2++;
        //         }
        //     }
        //     else
        //     {
        //         pattern.PB(ptr2);
        //         if (ptr1 == 1)
        //         {
        //             ptr1 = n;
        //         }
        //         else
        //         {
        //             ptr1--;
        //         }

        //         if (ptr2 == n)
        //         {
        //             ptr2 = 1;
        //         }
        //         else
        //         {
        //             ptr2++;
        //         }
        //     }
        //     times--;
        // }
        // cout << "odd\n";
        // for (auto x : pattern)
        // {
        //     cout << x << " ";
        // }
        // cout << "\n";
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