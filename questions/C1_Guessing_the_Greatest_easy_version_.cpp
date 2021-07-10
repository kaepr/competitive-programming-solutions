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

int ask(int l, int r)
{
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void solve()
{
    int n;
    cin >> n;
    int l = 1, r = n;
    int index = ask(l, r);
    // index--;

    bool is_left = true;

    if (index == 1)
    {
        is_left = false;
    }
    else
    {
        int x = ask(1, index);
        if (x != index)
        {
            //this means that max does not lie to the left
            is_left = false;
        }
    }

    int ans = -1;

    if (is_left)
    {
        //L = largest, SL = second largest
        //minimum index where ask(...) = SL is the answer
        //so the array is of the shape ........L...SL....

        l = 1, r = index;
        // if (l == r)
        // {
        //     cout << "! " << l << "\n";
        //     return;
        // }
        int ans = 0;
        while (l < (r - 1))
        {
            int m = (l + r) / 2;
            if (ask(min(m, index), max(m, index)) == index)
            {
                l = m;
                ans = m;
                // l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        ans = l;
        cout << "! " << ans << "\n";
    }
    else
    {
        //   ....SL....L...........
        l = index, r = n;
        int ans = 0;
        // if (l == r)
        // {
        //     cout << "! " << l << "\n";
        //     return;
        // }
        while (l < (r - 1))
        {
            int m = (l + r) / 2;
            if (ask(min(m, index), max(m, index)) == index)
            {
                r = m;
                ans = m;
                // r = m - 1;
            }
            else
            {
                l = m;
            }
        }
        ans = r;

        cout << "! " << ans << "\n";
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