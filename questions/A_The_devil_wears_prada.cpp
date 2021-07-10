#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int p, c, l;
    cin >> p >> c >> l;
    int b, s;
    cin >> b >> s;

    int profit = 0;
    for (int i = 0; i <= min(c, p / 2); i++)
    {
        // i means number of bags taken
        int currSum = b * i;
        int pRem = p - i * 2;
        currSum += s * (min(l, pRem/2));
        profit = max(currSum, profit);
        // cout<<"bags taken : "<<i<<" "<<" shoes taken : "<<
    }

    for (int i = 0; i <= min(l, p / 2); i++)
    {
        // i means number of shows taken
        int currSum = s * i;
        int pRem = p - i * 2;
        currSum += b * (min(c, pRem/2));
        profit = max(currSum, profit);
    }
    cout << profit << "\n";
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
        solve();
        t--;
    }

    return 0;
}