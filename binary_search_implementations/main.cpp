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
/*
These might be trivial for most users, but if you are like me, who sometimes confuse on when to use mid+1, rig-1 etc, here is a reliable method after considering many different implementation variants.

To find the index of the rightmost 1 in a monotonically decreasing function, for example a=[1,1,1,1,0,0,0]
Define check(i) to return true when a[i]=1, false otherwise.

int lef = 0, rig = n-1;
int ans = -1;
while (lef <= rig)
{
    int mid = (lef + rig) / 2;
    if (check(mid))
    {
        lef = mid + 1;
        ans = mid;
    }
    else
    {
            rig = mid - 1;
    }
}
 The answer is the last valid mid.Make sure that lef and rig are in bounds.If a is available or can be computed efficiently, you can instead do

 
 
                                                                                                    F0R(i, n) a[i] *= -1;
int ans = upper_bound(a, a + n, -1) - a - 1; // get index of rightmost 1
Careful if 1 doesn't exist in a.

To find the index of the leftmost 1 in a monotonically increasing function, for example a=[0,0,0,0,1,1,1]
In a similar way,

int lef = 0, rig = n-1;
int ans = -1;
while (lef <= rig)
{
    int mid = (lef + rig + 1) / 2;
    if (check(mid))
    {
        rig = mid - 1;
        ans = mid;
    }
    else
    {
        lef = mid + 1;
    }
}
Notice the ceiling in the definition of mid.This is to handle rig - lef equals one.If a is available or can be computed efficiently, you can instead do

                                                                                                     int ans = lower_bound(a, a + n, 1) - a; // get index of leftmost 1
Careful if 1 doesn't exist in a.

You can then solve most problems by implementing your own definition of check(). Time complexity is the time complexity of your check() function times logn. Thanks to marvenlee for inspiring this blog.

*/

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