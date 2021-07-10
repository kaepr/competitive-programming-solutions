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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == k)
    {
        cout << 1 << "\n";
        return;
    }

    int minn = INT_MAX;
    int currAns = 0;
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        currAns += a[i];
    }

    minn = min(minn, currAns);
    // trace(index);
    // trace(minn);
    // trace(index);
    for (int i = 1; i < n - k + 1; i++)
    {
        currAns += a[i + k - 1];
        currAns -= a[i - 1];
        // cout << "Sum of current segment : " + currAns << "\n";
        if (currAns < minn)
        {
            index = i;
            minn = min(minn, currAns);
        }
        // trace(currAns);
        // trace(minn);
        // trace(index);
    }
    cout << index + 1 << "\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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