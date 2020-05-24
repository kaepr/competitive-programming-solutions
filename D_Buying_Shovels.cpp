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

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == k)
    {
        cout << 1 << "\n";
    }
    else if (n < k)
    {
        cout << 1 << "\n";
    }
    else
    {
        if (isPrime(n) == 1)
        {
            cout << n << "\n";
        }
        else
        {
            int ans = 1e9;
            for (int i = 1; i <= k; i++)
            {
                int temp;
                if (n % i == 0)
                {
                    temp = n / i;
                    //cout << "temp is " << temp << "\n";
                }
                ans = min(ans, temp);
            }
            cout << ans << "\n";
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