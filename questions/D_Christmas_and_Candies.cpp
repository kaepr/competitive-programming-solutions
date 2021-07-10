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

void findTwoGroup(ll n)
{

    ll sum = n * (n + 1) / 2;

    ll group1Sum = sum / 2;
    // vector<int> group1, group2;

    ll sum1 = 0;
    ll sum2 = 0;

    for (ll i = n; i > 0; i--)
    {
        if (group1Sum - i >= 0)
        {

            // group1.push_back(i);
            sum1 += i;

            // Decrease sum of group1
            group1Sum -= i;
        }
        else
        {
            // group2.push_back(i);
            sum2 += i;
        }
    }

    cout << abs(sum1 - sum2) << "\n";
}

bool check(int N, int D)
{
    int temp = (N * (N + 1)) / 2 + D;
    return (temp % 2 == 0);
}

void solve()
{
    ll n;
    cin >> n;
    ll num = 0;
    while (true)
    {
        if (check(n, num))
        {
            cout << num << "\n";
            return;
        }
        num++;
    }
    // findTwoGroup(n);
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
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