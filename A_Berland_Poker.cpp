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

    int n, m, k;
    cin >> n >> m >> k;
    int a = n / k;
    int arr[k][a];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < a; j++)
        {
            arr[i][j] = 0;
        }
    }

    int mInPrevious = 60;
    int mInRow = 0;
    for (int i = 0; i < a; i++)
    {
        if (m > 0)
        {
            arr[0][i] = 1;
            m--;
        }
    }
    int first = 0;
    for (int i = 0; i < a; i++)
    {
        if (arr[0][i] == 1)
        {
            first++;
        }
    }
    // first has the maximum number of jokers
    k--;
    if (m <= 0)
    {
        cout << first << "\n";
    }
    else if (m % k == 0)
    {
        cout << first - m / k << "\n";
    }
    else
    {
        int diff = m / k + 1;
        cout << first - diff << "\n";
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