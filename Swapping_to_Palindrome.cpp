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

bool check(string s)
{
    int n = s.length();
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = n - 1;
    int left = -1, right = -1;
    int ans = 0;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
            continue;
        }

        if (l + 1 == r)
        {
            cout << "NO\n";
            return;
        }

        else
        {
            bool changed = false;

            if (!changed)
            {
                if (s[l] == s[r - 1])
                {
                    if (right != r)
                    {
                        right = r - 1;
                        changed = true;
                        swap(s[r], s[r - 1]);
                    }
                }
            }

            if (!changed)
            {
                if (s[l + 1] == s[r])
                {
                    if (left != l)
                    {
                        left = l + 1;
                        changed = true;
                        swap(s[l], s[l + 1]);
                    }
                }
            }

            if (changed)
            {
                l++;
                r--;
                ans++;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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