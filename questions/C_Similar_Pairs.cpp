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
    int n;
    cin >> n;
    vector<int> v(n);
    int a = 0, b = 0;
    for (int &e : v)
    {
        cin >> e;
        if (e % 2 == 0)
        {
            a++;
        }
        else
        {
            b++;
        }
    }

    if (a % 2 != b % 2)
    {
        cout << "NO\n";
    }
    else
    {
        if (a % 2 == 0)
        {
            cout << "YES\n";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (v[i] % 2 != v[j] % 2 && abs(v[i] - v[j]) == 1)
                    {
                        cout << "YES\n";
                        return;
                    }
                }
            }
            cout << "NO\n";
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