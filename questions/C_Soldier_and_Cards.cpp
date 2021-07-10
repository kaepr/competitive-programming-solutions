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
int x, y;
bool isSame(int arr1[], int arr2[], queue<int> q1, queue<int> q2)
{
    // bool f = true;
    for (int i = 0; i < x; i++)
    {
        int temp = q1.front();
        q1.pop();
        if (temp != arr1[i])
        {
            return false;
        }
    }

    for (int i = 0; i < y; i++)
    {
        int temp = q2.front();
        q2.pop();
        if (temp != arr2[i])
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;
    queue<int> q1, q2;
    // int arr1[n] = {0}, arr2[n] = {0};

    // int x, y;
    cin >> x;
    int arr1[x];
    for (int i = 0; i < x; i++)
    {
        cin >> arr1[i];
        q1.push(arr1[i]);
    }
    cin >> y;
    int arr2[y];
    for (int i = 0; i < y; i++)
    {
        cin >> arr2[i];
        q2.push(arr2[i]);
    }
    int cnt = 0;
    // trace(x, y);
    while (!q1.empty() && !q2.empty())
    {
        int t1 = q1.front();
        int t2 = q2.front();
        q1.pop();
        q2.pop();
        if (t1 > t2)
        {
            q1.push(t2);
            q1.push(t1);
        }
        else
        {
            //t2 > t1
            q2.push(t1);
            q2.push(t2);
        }
        if (isSame(arr1, arr2, q1, q2))
        {
            cout << "-1\n";
            return;
        }
        cnt++;
        if (cnt > 110)
        {
            cout << -1 << "\n";
            return;
        }
    }
    int win = 0;
    if (q1.empty())
    {
        win = 2;
    }
    else
    {
        win = 1;
    }
    cout << cnt << " " << win << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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