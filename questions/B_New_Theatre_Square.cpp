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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char temp;
            cin >> temp;
            if (temp == '.')
            {
                arr[i][j] = 1;
            }
            else if (temp == '*')
            {
                arr[i][j] = 0;
            }
        }
    }

    int ones = 0;
    int twos = 0;

    for (int i = 0; i < n; i++)
    {
        int prevWhite = 0;
        for (int j = 0; j < m; j++)
        {
            if (prevWhite == 1 && arr[i][j] == 1)
            {
                if (arr[i][j] == 1)
                {
                    twos++;
                    prevWhite = 0;
                    ones--;
                }
            }
            else
            {
                if (arr[i][j] == 1)
                {
                    ones++;
                    prevWhite = 1;
                }
                else if (arr[i][j] == 0)
                {
                    prevWhite = 0;
                }
            }
        }
        //printf("ones is %d twos is %d\n", ones, twos);
    }
    int totalPrice = 1e9;
    totalPrice = min(totalPrice, ones * x + twos * y);
    //printf("ones is %d twos is %d\n", ones, twos);
    totalPrice = min(totalPrice, ones * x + twos * x * 2);
    if (ones == 0 && twos == 0)
    {
        totalPrice = 0;
    }
    cout << totalPrice << "\n";
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