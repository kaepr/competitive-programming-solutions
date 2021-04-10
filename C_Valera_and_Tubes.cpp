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
int ptr1 = 1, ptr2 = 1, n, m, k;
bool f;
void print(int times)
{
    for (int x = 1; x <= times; x++)
    {
        /*
        ptr1 -> row number ( n )
        ptr2 -> column number ( m )
        */
        cout << ptr1 << " " << ptr2 << " ";
        if (f)
        {
            ptr2++;
        }
        else
        {
            ptr2--;
        }

        if (ptr2 == (m + 1))
        {
            // cout << "\n";
            ptr2 = m;
            ptr1++;
            f = false;
        }
        if (ptr2 == 0)
        {
            ptr2 = 1;
            ptr1++;
            f = true;
        }
    }
}

void solve()
{
    cin >> n >> m >> k;
    ptr1 = 1;
    ptr2 = 1;
    f = true;
    for (int i = 1; i <= k; i++)
    {
        if (i == k)
        {
            cout << (n * m - (k - 1) * 2) << " ";
            print(n * m - (k - 1) * 2);
        }
        else
        {
            cout << 2 << " ";
            print(2);
            cout << "\n";
        }
    }
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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