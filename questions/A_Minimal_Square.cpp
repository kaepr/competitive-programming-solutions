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
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 4 * (a * b) << "\n";
    }
    else
    {

        if (a > b)
        {
            if (2 * b > a)
            {
                cout << (a + b - abs(a - b)) * ((a + b - abs(a - b))) << "\n";
            }
            else
            {
                cout << a * a << "\n";
            }
        }
        else if (b > a)
        {
            if (2 * a > b)
            {
                cout << (a + b - abs(a - b)) * ((a + b - abs(a - b))) << "\n";
            }
            else
            {
                cout << b * b << "\n";
            }
        }
    }
}

int main()
{
    FAST int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}