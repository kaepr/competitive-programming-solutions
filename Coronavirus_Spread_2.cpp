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

void solve()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        // int x;
        // cin >> x;/
        // v.PB(x);
        cin >> v[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << "\n";

    int cnt = 0;

    int minn = n, maxx = 1;
    for (int i = 0; i < n; i++)
    {
        //assuming i'th is affected
        int newPos[n];
        // // int ind = i;
        // vi infec;
        // infec.PB(i + 1);
        // vi ind;
        set<int> st;
        st.insert(i);
        int total = 1;
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < n; k++)
            {
                newPos[k] = k + 1 + j * v[k];
            }
            for (auto x : st)
            {
                int val = newPos[x];
                for (int k = 0; k < n; k++)
                {
                    if (newPos[k] == val)
                    {
                        if (st.find(k) == st.end())
                        {
                            st.insert(k);
                            total++;
                        }
                    }
                }
            }
        }
        minn = min(minn, total);
        maxx = max(maxx, total);
    }
    // trace(minn, maxx);
    cout << minn << " " << maxx << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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