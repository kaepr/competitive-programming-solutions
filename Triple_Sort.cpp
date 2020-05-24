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
    int n, k;
    cin >> n >> k;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    bool swapping[n + 1];
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] != i)
            swapping[i] = true;
        else
            swapping[i] = false;
    }

    int count = 0;
    vector<tuple<int, int, int>> ans;
    vector<int> extra;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (swapping[i] == false)
        {
            continue;
        }
        else
        {
            int ind = i;
            int cycleLength = 0;
            vector<int> index(n + 1);
            int m = 1;
            while (swapping[ind] == true)
            {
                index[m++] = ind;
                swapping[ind] = false;
                ind = arr[ind];
                cycleLength += 1;
            }

            if (cycleLength % 2 == 1)
            {
                count += cycleLength / 2;
                for (int j = 1; j <= cycleLength / 2; j++)
                {
                    ans.emplace_back(tie(index[1], index[j * 2], index[j * 2 + 1]));
                }
            }
            else
            {
                count += (cycleLength / 2 - 1);

                for (int j = 1; j < cycleLength / 2; j++)
                {
                    ans.emplace_back(tie(index[1], index[j * 2], index[j * 2 + 1]));
                }

                extra.emplace_back(index[1]);
                extra.emplace_back(index[cycleLength]);

                if (extra.size() == 4)
                {
                    count += 2;
                    ans.emplace_back(tie(extra[0], extra[1], extra[2]));
                    ans.emplace_back(tie(extra[0], extra[3], extra[2]));
                    extra.clear();
                }
            }

            if (count > k)
            {
                flag = 1;
                break;
            }
        }
    }
    if (extra.size() > 0)
        flag = 1;

    if (flag == 1)
    {
        cout << "-1\n";
    }
    else
    {
        cout << count << "\n";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << get<0>(ans[i]) << " "
                 << get<1>(ans[i]) << " "
                 << get<2>(ans[i]) << "\n";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}