#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int possible(ll x, ll y, ll n, ll change)
{
    int totalNumbers = 0;
    if ((y - x) % change == 0 && (y - x) / change < n)
    {
        // cout << "y is " << y << " x is " << x << " change is " << change << "\n";
        // cout<<"num possible "
        return 1;
    }

    return 0;
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {

        int n, x, y;
        cin >> n >> x >> y;
        vector<int> ans;
        for (int d = 1; d <= y - x; d++)
        {
            if ((y - x) % d == 0)
            {
                vector<int> res;
                bool foundX = false;
                int curr = y;
                int need = n;
                while (curr >= 1 && need > 0)
                {
                    res.push_back(curr);
                    if (curr == x)
                    {
                        foundX = true;
                    }
                    need--;
                    curr -= d;
                }
                curr = y;
                while (need > 0)
                {
                    curr += d;
                    res.push_back(curr);
                    need--;
                }
                sort(res.begin(), res.end());
                if (need == 0 && foundX)
                {
                    if (ans.empty() || ans.back() > res.back())
                    {
                        ans = res;
                    }
                }
            }
        }
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << "\n";

        t--;
    }

    return 0;
}