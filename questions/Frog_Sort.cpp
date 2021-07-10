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
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    vi wt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        wt.PB(x);
        a.PB(MP(x, 0));
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i].second = x;
    }

    //a[i].first = weight, a[i].second = jump size

    // for (auto x : a)
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }

    int posLowestWeight = 0;
    sort(wt.begin(), wt.end());
    // for (auto x : wt)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    int lowestCurrentWeight = wt[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i].first == lowestCurrentWeight)
        {
            // trace(a[i].first, a[i].second);
            posLowestWeight = i;
        }
    }

    // trace(posLowestWeight);
    int ans = 0;
    int wtPtr = 1;
    while (wtPtr < n)
    {
        //finding position of the currentLowestWeight
        lowestCurrentWeight = wt[wtPtr];

        // trace(lowestCurrentWeight);

        int currPos = -1;
        int lenAdder = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i].first == lowestCurrentWeight)
            {
                currPos = i;
                lenAdder = a[i].second;
            }
        }
        if (currPos > posLowestWeight)
        {
            // cout << "HAPPENS\n";
            posLowestWeight = currPos;
        }
        else
        {
            //need to add some multiple of lenAdder to currPos till it becomes more than posLowestWeight
            int times = 0;
            while (posLowestWeight >= currPos)
            {
                currPos += lenAdder;
                times++;
            }
            posLowestWeight = currPos;
            ans += times;
        }
        wtPtr++;
        // trace(lowestCurrentWeight, posLowestWeight);
    }
    cout << ans << "\n";
    // trace(ans);
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