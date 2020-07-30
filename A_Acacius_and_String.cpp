#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

const string t = "abacaba";

bool contains(string s)
{
    int cnt = 0, n = s.size();
    for (int i = 0; i <= n - 7; i++)
    {
        if (s.substr(i, 7) == t)
            cnt++;
    }
    return (cnt == 1);
}

void process(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
            cout << 'd';
        else
            cout << s[i];
    }
    cout << "\n";
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (contains(s))
    {
        cout << "Yes\n";
        process(s);
        return;
    }
    for (int i = 0; i <= n - 7; i++)
    {
        string str = s;
        bool flag = true;
        for (int j = 0; j < 7; j++)
        {
            if (str[i + j] != '?' && str[i + j] != t[j])
            {
                flag = false;
                break;
            }
            str[i + j] = t[j];
        }
        if (flag && contains(str))
        {
            cout << "Yes\n";
            process(str);
            return;
        }
    }
    cout << "No\n";
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