#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

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

const int MOD = 1e9 + 7;
int n;
string s;

int calc(int left, int right, char c)
{
    if (right - left == 1)
    {
        if (s[left] == c)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    int leftHalf = 0, rightHalf = 0;

    int mid = (right + left) / 2;

    for (int i = left; i < mid; i++)
    {
        if (s[i] != c)
        {
            leftHalf++;
        }
    }

    for (int i = mid; i < right; i++)
    {
        if (s[i] != c)
        {
            rightHalf++;
        }
    }

    leftHalf += calc(mid, right, c + 1);
    rightHalf += calc(left, mid, c + 1);

    return min(leftHalf, rightHalf);
}

void solve()
{

    cin >> n;

    cin >> s;

    cout << calc(0, n, 'a') << "\n";
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