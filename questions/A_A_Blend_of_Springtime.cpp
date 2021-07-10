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
    string s;
    cin >> s;
    int n = s.length();
    int flag = 0;
    for (int i = 1; i < n - 1; i++)
    {

        int Aflag = 0;
        int Bflag = 0;
        int Cflag = 0;

        //checker
        if (s[i - 1] == 'C' || s[i] == 'C' || s[i + 1] == 'C')
        {
            Cflag = 1;
        }
        if (s[i - 1] == 'B' || s[i] == 'B' || s[i + 1] == 'B')
        {
            Bflag = 1;
        }
        if (s[i - 1] == 'A' || s[i] == 'A' || s[i + 1] == 'A')
        {
            Aflag = 1;
        }

        if (Aflag == 1 && Bflag == 1 && Cflag == 1)
        {
            flag = 1;
            cout << "Yes\n";
            return;
        }
    }
    if (flag == 0)
    {
        cout << "No\n";
    }
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