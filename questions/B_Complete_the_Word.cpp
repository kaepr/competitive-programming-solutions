#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

const int N = 10000;
int cnt[27];
string s;
int n;

bool valid()
{
    for (int i = 0; i < 26; i++)
        if (cnt[i] >= 2)
            return false;

    return true;
}

void fill()
{
    for (int i = 0; i < n; i++)
        if (s[i] == '?')
            s[i] = 'A';
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    n = s.length();

    if (n < 26)
    {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 25; i < n; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j >= i - 25; j--)
        {
            if(s[j] != '?')
                cnt[s[j] - 'A']++;
        }

        if (valid())
        {
            int cur = 0;
            while (cnt[cur] > 0)
                cur++;

            for (int j = i - 25; j <= i; j++)
            {
                if (s[j] == '?')
                {
                    s[j] = cur + 'A';
                    cur++;

                    while (cnt[cur] > 0)
                        cur++;
                }
            }
            fill();
            cout << s << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";

    return 0;
}