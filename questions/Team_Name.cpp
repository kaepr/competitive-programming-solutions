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
    vector<string> v;
    map<char, set<string>> mp2;
    // set<char> st;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        // v.PB(s);
        // string str = v[i];
        char a = str[0];
        // st.insert(a);
        str.erase(0, 1);
        mp2[a].insert(str);
    }

    int ans = 0, cnt = 0;

    for (auto x : mp2)
    {
        for (auto y : mp2)
        {
            int val = 0;
            if (y.first != x.first)
            {
                set<string> st;
                for (auto str : x.second)
                {
                    if (y.second.find(str) != y.second.end())
                    {
                        // trace(str);
                        st.insert(str);
                    }
                }

                // for (auto str : y.second)
                // {
                //     trace(str);
                //     if (x.second.find(str) != x.second.end())
                //     {
                //         //in both
                //     }
                // }

                int common = st.size();
                // trace(common);
                ans += (x.second.size() - common) * (y.second.size() - common);
            }

            ans += val;
        }
        cnt++;
    }

    cout << ans << "\n";
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