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

const int N = 1e5 + 5;
int node[4 * N]; // node[x] stores sum in node x

/*

                1
            2        3
          4   5    6    7
    
    if the node number is v
    --- then right node would be 2v
    --- then left node would be 2v + 1

*/

void update(int v, int tl, int tr, int id, int val)
{
    // v -> node number
    //tl, tr -> node range
    //id -> updating point
    //val -> new value

    if (tl == id && tr == id)
    {
        //found
        node[v] = val;
        return;
    }
    if (id > tr || id < tl)
    {
        //not inside node range
        return;
    }

    int tm = (tl + tr) / 2;
    // two parts, [tl, tm] and [tm + 1, tr]
    update(2 * v, tl, tm, id, val);
    update(2 * v + 1, tm + 1, tr, id, val);
    node[v] = node[2 * v] + node[2 * v + 1]; // sum of left and right
}

//l,r is the query range
int query(int v, int tl, int tr, int l, int r)
{
    //no overlap
    if (tl > r || tr < l)
    {
        return 0;
    }
    //fully within
    if (l <= tl && tr <= r)
    {
        // l...tl...tr...r
        //getting the present node
        // cout << "HAPPENS\n";
        return node[v];
    }
    int tm = (tl + tr) / 2;
    // two parts, [tl, tm] and [tm + 1, tr]
    int ans = 0;
    ans += query(2 * v, tl, tm, l, r);
    ans += query(2 * v + 1, tm + 1, tr, l, r);
    return ans;
}

void solve()
{
    // initial values = v,tl,tr = 1, 0 , len - 1
    update(1, 0, N - 1, 0, 123);
    update(1, 0, N - 1, 2, 5);
    update(1, 0, N - 1, 3, 6);
    update(1, 0, N - 1, 6, 10000);
    cout << query(1, 0, N - 1, 0, 6);
}

// 0 ... (2 ... 3) ... N - 1

// l

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