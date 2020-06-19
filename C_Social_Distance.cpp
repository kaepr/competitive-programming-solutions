#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    //cin >> k;
    //int n = s.length();
    int res = 0;
    for (int i = 0; i < n;)
    {
        int j = i + 1;
        for (; j < n && s[j] != '1'; j++);

        int left = s[i] == '1' ? k : 0;
        int right = j < n && s[j] == '1' ? k : 0;
        int len = j - i;
        if (left == k)
        {
            len--;
        }

        len -= left + right;

        if (len > 0)
        {
            res += (len + k) / (k + 1);
        }
        i = j;
    }
    printf("%d\n", res);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}