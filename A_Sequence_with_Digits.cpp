#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define loops(i, a, b, step) for (int i = a; i < b; i += step)
#define looprs(i, a, b, step) for (int i = a; i >= b; i -= step)
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
#define all(a) a.begin(), a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

ll largest = 0;
ll smallest = 9;

void Digits(ll n)
{

    while (n)
    {
        ll r = n % 10;

        // Find the largest digit
        largest = max(r, largest);

        // Find the smallest digit
        smallest = min(r, smallest);

        n = n / 10;
    }
    //cout << largest << " " << smallest;
}

void solve()
{
    ll a, k;
    cin >> a >> k;
    ll ans = 0;
    if (k == 1)
    {
        cout << a << "\n";
        return;
    }
    for (ll i = 0; i < k - 1; i++)
    {
        ll temp = a;
        ll low = 9, high = 0;
        while (temp)
        {
            ll r = temp % 10;
            low = min(low, r);
            high = max(high, r);
            temp = temp / 10;
        }
        //cout << "this is low " << low << "this is high" << high << "\n";
        if (k == 1)
        {
            ans = a;
        }
        else
        {
            ans = a + low * high;
        }
        a = ans;
    }
    cout << ans << "\n";
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}