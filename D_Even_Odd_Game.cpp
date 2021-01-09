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
    ll n;
    cin >> n;
    vector<ll> e, o;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x % 2 == 0)
        {
            e.PB(x);
        }
        else
        {
            o.PB(x);
        }
    }
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    reverse(e.begin(), e.end());
    reverse(o.begin(), o.end());
    ll currEvenSum = 0, currOddSum = 0;

    ll ptr1 = 0, ptr2 = 0;
    bool flag = true;
    while (ptr1 < e.size() && ptr2 < o.size())
    {
        if (flag)
        {
            //alice turn
            if (e[ptr1] >= o[ptr2])
            {
                currEvenSum += e[ptr1];
                ptr1++;
            }
            else
            {
                ptr2++;
            }
            flag = false;
        }
        else
        {
            //bob turn
            if (o[ptr2] >= e[ptr1])
            {
                currOddSum += o[ptr2];
                ptr2++;
            }
            else
            {
                ptr1++;
            }

            flag = true;
        }
    }

    while (ptr1 < e.size())
    {
        if (flag)
        {
            currEvenSum += e[ptr1];
            ptr1++;
            flag = false;
        }
        else
        {
            ptr1++;
            flag = true;
        }
    }

    while (ptr2 < o.size())
    {
        if (flag)
        {
            ptr2++;
            flag = false;
        }
        else
        {
            currOddSum += o[ptr2];
            ptr2++;
            flag = true;
        }
    }

    if (currEvenSum > currOddSum)
    {
        cout << "Alice\n";
    }
    else if (currEvenSum < currOddSum)
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Tie\n";
    }
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