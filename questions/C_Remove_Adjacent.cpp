#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    while (1)
    {
        int f = 0, alpha = 0, pos = 0;
        n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (i != 0 and s[i] - s[i - 1] == 1 and alpha < s[i] - 'a')
            {
                f = 1;
                alpha = s[i] - 'a';
                pos = i;
            }
            if (i != n - 1 and s[i] - s[i + 1] == 1 and alpha < s[i] - 'a')
            {
                f = 1;
                alpha = s[i] - 'a';
                pos = i;
            }
        }

        if (f == 0)
            break;

        cnt++;
        s.erase(pos, 1);
    }
    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}