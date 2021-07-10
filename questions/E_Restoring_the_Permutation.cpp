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
    int q[n], minn[n], maxx[n];
    memset(q, 0, sizeof(q));
    memset(maxx, 0, sizeof(maxx));
    memset(minn, 0, sizeof(minn));
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    int lastElm = q[0];
    minn[0] = lastElm;
    maxx[0] = lastElm;
    set<int> st;
    st.insert(lastElm);
    for (int i = 1; i < n; i++)
    {
        if (q[i] == lastElm)
        {
            //same, can ignore
        }
        else
        {
            //new element
            lastElm = q[i];
            minn[i] = lastElm;
            maxx[i] = lastElm;
            st.insert(lastElm);
        }
    }
    vi rem;
    for (int i = 1; i <= n; i++)
    {
        if (st.find(i) == st.end())
        {
            rem.PB(i);
        }
    }

    int ptr = 0;
    sort(rem.begin(), rem.end());
    for (int i = 0; i < n; i++)
    {
        if (minn[i] == 0)
        {
            minn[i] = rem[ptr];
            ptr++;
        }
    }

    int val = maxx[0];
    for (int i = 0; i < n; i++)
    {
        if (maxx[i] == 0)
        {
            //find the greatest element <= maxx[i]
            int index = lower_bound(rem.begin(), rem.end(), val) - rem.begin();
            index--;
            maxx[i] = rem[index];
            rem.erase(rem.begin() + index);
        }
        else
        {
            val = maxx[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << minn[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << maxx[i] << " ";
    }
    cout << "\n";
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