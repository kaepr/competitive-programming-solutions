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
    string first, second, type;
    cin >> first >> second >> type;
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    transform(second.begin(), second.end(), second.begin(), ::tolower);
    transform(type.begin(), type.end(), type.begin(), ::tolower);
    for (int i = 0; i < type.length(); i++)
    {
        char temp = type[i];
        //cout << "the letter is " << temp << "\n";
        int index = 0;
        for (int j = 0; j < first.length(); j++)
        {
            if (first[j] == temp)
            {
                cout << second[i];
            }
        }
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