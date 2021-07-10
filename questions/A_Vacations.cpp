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

/*
1 on this day the gym is closed and the contest is not carried out;
2 on this day the gym is closed and the contest is carried out;
3 on this day the gym is open and the contest is not carried out;
4 on this day the gym is open and the contest is carried out.
*/

int n;
int dp[105][3];
int a[105];

/*
last 
0 = taken rest previously
1 = taken contest previously
2 = taken gym previously
*/

int calc(int day, int last)
{
    if (day >= n)
    {
        return 0;
    }
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    if (a[day] == 0)
    {

        //we can only take rest today
        dp[day][last] = calc(day + 1, 0) + 1;
    }
    else if (a[day] == 1)
    {
        // cout << "goes here\n";
        //gym is closed, so we can only go to contest. If we went to contest last day, then not possible
        if (last == 1)
        {
            //as contest was done previously, so only rest today
            dp[day][last] = calc(day + 1, 0) + 1;
        }
        else
        {
            // we can give contest
            dp[day][last] = calc(day + 1, 1) + 0;
        }
    }
    else if (a[day] == 2)
    {
        //contest is closed, so we can only go to gym. If we went to gym last day, then not possible
        if (last == 2)
        {
            //as gym was done previously, so only rest today
            dp[day][last] = calc(day + 1, 0) + 1;
        }
        else
        {
            // we can go to gym
            dp[day][last] = calc(day + 1, 2) + 0;
        }
    }
    else if (a[day] == 3)
    {
        // both open, so we can go either way ( depending upon last )
        int con, gy;
        if (last == 1)
        {
            con = INT_MAX;
        }
        else
        {
            con = calc(day + 1, 1);
        }

        if (last == 2)
        {
            gy = INT_MAX;
        }
        else
        {
            gy = calc(day + 1, 2);
        }

        dp[day][last] = min(con, gy);
    }
    // trace(dp[day][last]);
    return dp[day][last];
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    calc(0, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[0][0] << "\n";
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