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

int cnt(vector<int> arr, int k)
{
    // for (auto x : arr)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // trace(k);
    int j = 0;
    int curr_sum = 0;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        curr_sum += arr[i];
        if (curr_sum == k)
        {
            ans += (i - j);
            j = i + 1;
            curr_sum = 0;
        }
        else if (curr_sum > k)
        {
            return -1;
        }
        // trace(ans);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vi a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.PB(x);
    }

    int total_sum = 0;

    for (auto x : a)
    {
        total_sum += x;
    }

    vi divisors;
    for (int i = 1; i * i <= total_sum; i++)
    {
        if (total_sum % i == 0)
        {
            if (total_sum / i == i)
            {
                divisors.PB(i);
            }
            else
            {
                divisors.PB(i);
                divisors.PB(total_sum / i);
            }
        }
    }

    int ans = n - 1;

    // for (auto x : divisors)
    // {
    //     cout << x << " ";
    // }

    for (auto x : divisors)
    {
        int curr = cnt(a, x);
        if (curr != -1)
        {
            ans = min(ans, curr);
        }
    }
    cout << ans << "\n";

    // cout << "\n";s
    // cout << "NEWCASE\n";
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