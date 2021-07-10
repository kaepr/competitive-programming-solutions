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

using key = pair<int, pair<int, int>>;
struct cmp
{
    bool operator()(const key &k1, const key &k2)
    {
        //length of first, second
        int l1 = k1.first;
        int l2 = k2.first;
        if (l1 != l2)
        {
            return l1 < l2;
        }

        //start indexes of the subarrays
        int i1 = k1.second.first;
        int i2 = k2.second.first;
        return i1 > i2;
    }
};

const int MAXN = 2e5 + 10;
int arr[MAXN];

void solve()
{
    int n;
    cin >> n;
    int k = 1;
    priority_queue<key, vector<key>, cmp> pq;

    //starting index
    pq.push({n, {0, n - 1}});
    int len, mid, right, left;
    while (!pq.empty())
    {
        //max length of interval to be chosen
        key fr = pq.top();

        pq.pop();
        len = fr.first;
        left = fr.second.first;
        right = fr.second.second;
        if (left == right)
        {
            arr[left] = k;
            k++;
            continue;
        }

        if (len & 1)
        {
            mid = left + (right - left) / 2;
        }
        else
        {
            mid = (left + right - 1) / 2;
        }
        arr[mid] = k;
        k++;
        if (mid + 1 <= right)
        {
            //{start, end} is valid
            pq.push({right - mid, {mid + 1, right}});
        }
        if (left <= mid - 1)
        {
            pq.push({mid - left, {left, mid - 1}});
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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