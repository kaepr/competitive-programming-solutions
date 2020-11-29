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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q > 0)
    {
        int l, r;
        cin >> l >> r;
        string snew = "";
        bool flag = false;
        for (int i = l - 1; i < r; i++)
        {
            snew += s[i];
        }
        // trace(snew);
        //last char in that is
        char lastInSnew = s[r - 1];
        char firstChar = s[l - 1];
        // trace(lastInSnew);
        // trace(firstChar);
        int oneCnt = 0, lastCnt = 0;
        for (int i = l - 2; i >= 0; i--)
        {
            if (s[i] == firstChar)
            {
                oneCnt++;
            }
        }

        for (int i = r; i < n; i++)
        {
            if (s[i] == lastInSnew)
            {

                lastCnt++;
            }
        }

        // trace(lastCnt);
        // trace(oneCnt);
        if (lastCnt > 0 || oneCnt > 0)
        {
            flag = true;
        }

        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        q--;
    }
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