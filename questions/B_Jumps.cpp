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

vector<ll> v;

// ll getClosest(ll, ll, ll);

// // Returns element closest to target in arr[]
// ll findClosest(ll v[], ll n, ll target)
// {
//     // Corner cases
//     if (target <= v[0])
//         return v[0];
//     if (target >= v[n - 1])
//         return v[n - 1];

//     // Doing binary search
//     ll i = 0, j = n, mid = 0;
//     while (i < j)
//     {
//         mid = (i + j) / 2;

//         if (v[mid] == target)
//             return v[mid];

//         /* If target is less than vay element,
//             then search in left */
//         if (target < v[mid])
//         {

//             // If target is greater than previous
//             // to mid, return closest of two
//             if (mid > 0 && target > v[mid - 1])
//                 return getClosest(v[mid - 1],
//                                   v[mid], target);

//             /* Repeat for left half */
//             j = mid;
//         }

//         // If target is greater than mid
//         else
//         {
//             if (mid < n - 1 && target < v[mid + 1])
//                 return getClosest(v[mid],
//                                   v[mid + 1], target);
//             // update i
//             i = mid + 1;
//         }
//     }

//     // Only single element left after search
//     return v[mid];
// }

// Method to compare which one is the more close.
// We find the closest by taking the difference
// between the target and both values. It assumes
// that val2 is greater than val1 and target lies
// // between these two.
// int getClosest(int val1, int val2,
//                int target)
// {
//     if (target - val1 >= val2 - target)
//         return val2;
//     else
//         return val1;
// }

void solve()
{
    ll x;
    cin >> x;
    if (binary_search(v.begin(), v.end(), x))
    {
        cout << lower_bound(v.begin(), v.end(), x) - v.begin() + 1 << "\n";
    }
    else
    {
        // cout << "goes here\n";
        // trace(x);
        ll ptrBelowX = lower_bound(v.begin(), v.end(), x) - v.begin();
        ptrBelowX--;
        ll ptrAboveX = upper_bound(v.begin(), v.end(), x) - v.begin();

        ll elm1 = v[ptrBelowX];
        ll elm2 = v[ptrAboveX];

        // trace(ptrBelowX);
        // trace(ptrAboveX);
        // trace(elm1);
        // trace(elm2);

        ll diff1 = abs((x - elm1));
        ll diff2 = (elm2 - x);
        // trace(diff1);
        // trace(diff2);
        ll ans1 = lower_bound(v.begin(), v.end(), elm1) - v.begin() + 1 + diff1;
        ll ans2 = lower_bound(v.begin(), v.end(), elm2) - v.begin() + 1 + diff2;
        // trace(ans1);
        // trace(ans2);
        if (diff1 == diff2)
        {
            cout << ans2 << "\n";
        }
        else
        {
            cout << min(ans1, ans2) << "\n";
        }

        // cout << ptrAboveX + 1 + abs(elm2 - x) << "\n";
    }
}

int main()
{

    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll y = 0, k = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        v.PB(y + k);
        y = y + k;
        k++;
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << "\n";

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}