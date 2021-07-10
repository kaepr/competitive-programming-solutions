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
    int ans = 1e9;
    // calculating rows
    //n
    if (n > m)
    {
        int temp = 0;
        temp = (n / 2) * m;
        if (n % 2 != 0)
        {
            if (m % 2 == 0)
            {
                temp += m / 2;
            }
            else
            {
                temp = temp + m / 2 + 1;
            }
        }
        ans = min(temp, ans);
    }
    else if (m > n)
    {
        int temp = 0;
        temp = (m / 2) * n;
        if (m % 2 != 0)
        {
            if (n % 2 == 0)
            {
                temp += n / 2;
            }
            else
            {
                temp = temp + n / 2 + 1;
            }
        }
        ans = min(temp, ans);
    }
    else if (n == m)
    {
        int temp = 0;
        if (n % 2 == 0)
        {
            temp = (n / 2) * m;
        }
        else if (n % 2 != 0)
        {
            temp += (n / 2) * m;
            temp = temp + (m / 2) + 1;
        }
        ans = min(temp, ans);
    }
    cout << ans << "\n";
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