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
    string a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << "\n";
        return;
    }
    //a to b
    vector<int> ans;
    int ptr = n - 1;
    while (true && ptr >= 0)
    {
        // trace(ptr);
        // cout << "STARTS AT\n";
        // trace(a);
        if (a[ptr] == b[ptr])
        {
            ptr--;
            continue;
        }

        if (b[ptr] == a[0])
        {
            if (a[0] == '0')
            {
                a[0] = '1';
            }
            else if (a[0] == '1')
            {
                a[0] = '0';
            }
            ans.PB(1);
        }

        // cout << "BEFORE FLIPS\n";
        // trace(a);

        for (int i = 0; i <= ptr; i++)
        {
            if (a[i] == '0')
            {
                a[i] = '1';
            }
            else if (a[i] == '1')
            {
                a[i] = '0';
            }
        }

        // cout << "BEFORE REV\n";
        // trace(a);

        for (int i = 0; i <= ptr / 2; i++)
        {
            swap(a[i], a[ptr - i]);
        }

        // trace(a);
        // cout << "ENDS AT\n";
        // trace(a);
        ans.PB(ptr + 1);
        ptr--;
    }
    cout << ans.size() << " ";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
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