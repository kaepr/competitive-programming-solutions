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

int op1 = 1, op2 = 0;
int a[100005];
int ans = 0;
int flag = 1;
int i, n;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (i = 1; i < n; i++)
    {
        if (flag == 1)
        {
            if (a[i - 1] == a[i])
            {
                op1++;
            }
            else
            {
                flag = 2;
                op2++;
                continue;
            }
        }
        if (flag == 2)
        {
            if (a[i - 1] == a[i])
            {
                op2++;
                if (op2 == op1)
                {
                    if (ans < op2)
                        ans = op2;

                    op1 = op2;
                    op2 = 0;
                    flag = 1;
                    continue;
                }
            }
            else
            {
                if (op2 <= op1)
                {
                    ans = max(ans, op2);
                }

                op1 = op2;
                op2 = 1;
                flag = 2;
                continue;
            }
        }
    }
    ans = max(ans, op2);
    cout << ans * 2;
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