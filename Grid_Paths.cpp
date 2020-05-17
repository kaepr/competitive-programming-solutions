#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define loops(i, a, b, step) for (int i = a; i < b; i += step)
#define looprs(i, a, b, step) for (int i = a; i >= b; i -= step)
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
#define all(a) a.begin(), a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

bool visited[7][7];
int sol = 0;

//meas currently at position (x,y), hacing used pos characters of string
void solve(int pos, int x, int y, const string &s, char prev = 'R')
{

    if (x == 6 and y == 0)
    {
        //now we are at the bottom left square
        //if we are the final step
        if (pos == 48)
        {
            ++sol;
        }
        //else do nothing, as it won't be possible to continue this path
        return;
    }

    if (prev == 'U' and (x == 0 or visited[x - 1][y]) and y > 0 and y < 6 and !visited[x][y - 1] and !visited[x][y + 1])
        return;
    if (prev == 'D' and (x == 6 or visited[x + 1][y]) and y > 0 and y < 6 and !visited[x][y - 1] and !visited[x][y + 1])
        return;
    if (prev == 'L' and (y == 0 or visited[x][y - 1]) and x > 0 and x < 6 and !visited[x - 1][y] and !visited[x + 1][y])
        return;
    if (prev == 'R' and (y == 6 or visited[x][y + 1]) and x > 0 and x < 6 and !visited[x - 1][y] and !visited[x + 1][y])
        return;

    //solveing steps
    if (s[pos] == '?')
    {
        //trying all the differene possibilties
        if (x > 0 and !visited[x - 1][y])
        {
            //go up
            visited[x - 1][y] = 1; //visited (x-1, y) as visited
            solve(pos + 1, x - 1, y, s, 'U');
            visited[x - 1][y] = 0;
        }
        if (x < 6 and !visited[x + 1][y])
        { // Go down
            visited[x + 1][y] = 1;
            solve(pos + 1, x + 1, y, s, 'D');
            visited[x + 1][y] = 0;
        }
        if (y > 0 and !visited[x][y - 1])
        { // Go left
            visited[x][y - 1] = 1;
            solve(pos + 1, x, y - 1, s, 'L');
            visited[x][y - 1] = 0;
        }
        if (y < 6 and !visited[x][y + 1])
        { // Go right
            visited[x][y + 1] = 1;
            solve(pos + 1, x, y + 1, s, 'R');
            visited[x][y + 1] = 0;
        }
    }
    else
    {
        if (s[pos] == 'U')
            --x; // Only possible move is to go up
        if (s[pos] == 'D')
            ++x; // Only possible move is to go down
        if (s[pos] == 'L')
            --y; // Only possible move is to go left
        if (s[pos] == 'R')
            ++y; // Only possible move is to go right
        if (x < 0 or y < 0 or x >= 7 or y >= 7 or visited[x][y])
            return;
        visited[x][y] = 1;
        solve(pos + 1, x, y, s, s[pos]);
        visited[x][y] = 0;
    }
}

int main()
{
    string s;
    cin >> s;
    visited[0][0] = 1;
    solve(0, 0, 0, s);
    cout << sol << "\n";
    return 0;
}