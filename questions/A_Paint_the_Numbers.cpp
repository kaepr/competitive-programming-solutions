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

typedef struct elm
{
    int x;
    int vis;
} elm;

bool compare(elm a, elm b)
{
    return a.x < b.x;
}

void solve()
{
    int n;
    cin >> n;
    elm a[n];
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a[i].x = temp;
        a[i].vis = 0;
    }

    sort(a, a + n, compare);
    for (int i = 0; i < n; i++)
    {
        int temp = a[i].x;
        if (a[i].vis == 0)
        {
            total++;
            for (int j = i; j < n; j++)
            {
                if (a[j].x % temp == 0)
                {
                    a[j].vis = 1;
                }
            }
        }
    }
    cout << total;
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