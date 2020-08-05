#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int o = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            o++;
        else
            c++;
    }
    if (o != c)
    {
        cout << -1 << "\n";
    }
    else
    {
        int cnt = 0, l = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                cnt++;
            else
            {
                cnt--;
                if (cnt < 0)
                {
                    ans += 2;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}