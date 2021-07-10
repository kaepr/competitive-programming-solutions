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

void pythagoreanTriplets(int limit)
{

    // triplet: a^2 + b^2 = c^2
    int a, b, c = 0;

    // loop from 2 to max_limitit
    int m = 2;

    // Limiting c would limit
    // all a, b and c
    ll cnt = 0;
    while (c < limit)
    {

        // now loop on j from 1 to i-1
        for (int n = 1; n < m; ++n)
        {
            // Evaluate and print triplets using
            // the relation between a, b and c
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;

            if (c != a - b)
            {
                continue;
            }

            if (c > limit)
                break;

            cnt++;
            // printf("%d %d %d\n", a, b, c);
        }
        m++;
    }
    trace(cnt);
}

void solve()
{
    ll n;
    cin >> n;
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    pythagoreanTriplets(1000000000);

    // ll cnt = 0;
    // for (ll i = 1; i <= 9; i++)
    // {
    //     for (ll j = 1; j <= 9; j++)
    //     {
    //         ll val1 = (i + j) * (i + j);
    //         ll val2 = (j * j - i * i) * (j * j - i * i);
    //         if (val2 == val1 && ((i * i + j * j) == (i * i - j * j + 2 * i * j)))
    //         {
    //             trace(i, j);
    //             cnt++;
    //         }
    //     }
    // }
    // trace(cnt);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}