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

int powmod(int x, int y)
{
    int res = 1;
    // x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool isAscend = true;
    int index;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            index = i;
            isAscend = false;
            break;
        }
    }

    if (isAscend)
    {
        cout << 0 << "\n";
        return;
    }

    int maxDiff = 0;
    int maxTillHere = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > maxTillHere)
        {
            maxTillHere = a[i];
        }
        else
        {
            maxDiff = max(maxDiff, maxTillHere - a[i]);
        }
        // trace(maxTillHere, maxDiff);
    }

    int currTime = 1;
    int sum = powmod(2, currTime - 1);
    while (sum < maxDiff)
    {
        // trace(sum);
        currTime++;
        sum += powmod(2, currTime - 1);
    }
    cout << currTime << "\n";
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