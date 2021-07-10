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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ptr1 = 0, ptr2 = n - 1;
    int prevEatA = 0, prevEatB = 0, a_total = 0, b_total = 0, cnta = 0, cntb = 0;
    bool move = true;
    while (ptr1 <= ptr2)
    {
        if (move)
        {
            move = false;
            int curr = 0;
            while (curr <= prevEatB && ptr1 <= ptr2)
            {
                curr += a[ptr1];

                ptr1++;
            }
            cnta++;
            prevEatA = curr;
            a_total += curr;
            // trace(prevEatA);
        }
        else
        {
            move = true;
            int curr = 0;
            while (curr <= prevEatA && ptr2 >= ptr1)
            {
                curr += a[ptr2];

                ptr2--;
            }
            cntb++;
            prevEatB = curr;
            b_total += curr;
            // trace(prevEatB);
        }
    }
    cout << cnta + cntb << " " << a_total << " " << b_total << "\n";
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