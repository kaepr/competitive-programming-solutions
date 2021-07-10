#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    string a = "hello";
    int sptr = 0;
    int aptr = 0;
    int flag = 0;
    while (sptr < s.length())
    {
        if (s[sptr] == a[aptr])
        {
            aptr++;
            if (aptr == a.length())
            {
                flag = 1;
            }
        }

        sptr++;
    }
    if (flag)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}