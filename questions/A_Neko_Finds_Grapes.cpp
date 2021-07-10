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
    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int totalOddKey = 0;
    int totalEvenKey = 0;
    int totalOddChest = 0;
    int totalEvenChest = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            totalEvenChest++;
        }
        else
        {
            totalOddChest++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (b[i] % 2 == 0)
        {
            totalEvenKey++;
        }
        else
        {
            totalOddKey++;
        }
    }

    int aa = min(totalEvenKey, totalOddChest);
    int bb = min(totalEvenChest, totalOddKey);

    cout << aa + bb;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}