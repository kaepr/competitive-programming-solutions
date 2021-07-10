#include <bits/stdc++.h>
#define MOD 1000000007
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define FILE_READ_IN freopen("input.txt", "r", stdin);
#define FILE_READ_OUT freopen("output.txt", "w", stdout);
using namespace std;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

void solve()
{
    int l, r, a;
    cin >> l >> r >> a;
    int ans = 0;
    if (l < r)
    {
        int temp = r - 1;
        int t = 1;
        l += min(temp, a);
        a -= (l - t);
        if (l < r)
        {
            r = l;
            ans = l + r + a - (a % 2);
        }
    }
    else if (r < l)
    {
        swap(l, r);
        int temp = r - l;
        int t = l;
        l = l + min(temp, a);
        a -= (l - t);
        if (l < r)
            r = l;
        ans = l + r + a - (a % 2);
    }
    else
    {
        ans = l + r + a - (a % 2);
    }
    cout << ans << "\n";
}

int main()
{
    FAST int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}