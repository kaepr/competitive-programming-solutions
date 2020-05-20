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

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int calcAngle(double h, double m)
{
    // validate the input
    if (h < 0 || m < 0 || h > 12 || m > 60)
        printf("Wrong input");

    if (h == 12)
        h = 0;
    if (m == 60)
        m = 0;

    // Calculate the angles moved
    // by hour and minute hands
    // with reference to 12:00
    int hour_angle = 0.5 * (h * 60 + m);
    int minute_angle = 6 * m;

    // Find the difference between two angles
    int angle = abs(hour_angle - minute_angle);

    // Return the smaller angle of two possible angles
    angle = min(360 - angle, angle);

    return angle;
}

int findAngle(int hour, int min)
{
    // find position of hour's hand
    int h = (hour * 360) / 12 + (min * 360) / (12 * 60);

    // find position of minute's hand
    int m = (min * 360) / (60);

    // calculate the angle difference
    int angle = abs(h - m);

    // consider shorter angle and return it
    if (angle > 180)
        angle = 360 - angle;

    return angle;
}

int main()
{
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    int hourAngle = 30 * h;
    int minAngle = m;
    int angle = (hourAngle - minAngle);
    if (angle >= 180)
    {
        angle = 360 - angle;
    }
    angle = abs(angle);
    cout << angle << "\n";
    double ans = a * a + b * b - 2 * a * b * cos(angle);
    cout << sqrt(ans);

    return 0;
}