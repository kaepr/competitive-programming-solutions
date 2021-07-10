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
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'Q')
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                if (s[j] == 'A')
                {
                    for (int k = j + 1; k < s.length(); k++)
                    {
                        if (s[k] == 'Q')
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}

int main()
{
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}