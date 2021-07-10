#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define pb push_back
#define F first
#define S second
#define mp make_pair

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

string s;
int n, k;

int calcPower(int magnetPos, int ironPos)
{
    return k + 1 - abs(magnetPos - ironPos);
}

int calc(int start, int end)
{
    // trace(start, end);
    int cnt = 0;
    vi magnets, irons;
    set<int> mset, iset, mset2, iset2;
    for (int i = start; i <= end; i++)
    {
        if (s[i] == 'M')
        {
            magnets.pb(i);
            mset.insert(i);
            mset2.insert(i);
        }
        else if (s[i] == 'I')
        {
            irons.pb(i);
            iset.insert(i);
            iset2.insert(i);
        }
    }
    // cout << "Magnets positions\n";
    // for (auto x : mset)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // cout << "Iron positions\n";
    // for (auto x : iset)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    int numValidI = 0, numValidM = 0;

    for (auto x : iset)
    {
        int temp = 0;
        for (auto y : mset)
        {
            if (k + 1 - (abs(y - x)) > 0)
            {
                temp++;
            }
        }
        if (temp > 0)
        {
            numValidI++;
        }
    }

    for (auto x : mset)
    {
        int temp = 0;
        for (auto y : iset)
        {
            if (k + 1 - (abs(y - x)) > 0)
            {
                temp++;
            }
        }
        if (temp > 0)
        {
            numValidM++;
        }
    }
    // trace(numValidM);
    // trace(numValidI);
    return min(numValidI, numValidM);
}

void solve()
{
    cin >> n >> k;
    cin >> s;
    vi irons;
    vi walls;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'X')
        {
            walls.pb(i);
        }
    }
    int ans = 0;
    int ptr = 0;
    // if (walls.size() == 0)
    // {
    //     ans += calc(0, n - 1);
    // }
    // else
    // {
    for (auto x : walls)
    {
        ans += calc(ptr, x - 1);
        ptr = x + 1;
    }
    // }
    ans += calc(ptr, n - 1);
    cout << ans << "\n";
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