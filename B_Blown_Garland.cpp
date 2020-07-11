#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, k, n;
    string s;
    int y = 0, r = 0, b = 0, g = 0;
    int rc = -1, yc = -1, bc = -1, gc = -1;
    cin >> s;
    n = s.length();
    for (i = 0; i < n; i += 4)
    {
        k = 1;
        for (j = i; j < i + 4; j++)
        {
            if (s[j] == 'Y')
                yc = k;
            else if (s[j] == 'R')
                rc = k;
            else if (s[j] == 'B')
                bc = k;
            else if (s[j] == 'G')
                gc = k;

            k++;
        }
    }

    for (i = 0; i < n; i += 4)
    {
        k = 1;
        for (j = i; j < i + 4; j++)
        {
            if (s[j] == '!')
            {
                if (k == yc)
                {
                    y++;
                }
                else if (k == rc)
                {
                    r++;
                }
                else if (k == gc)
                {
                    g++;
                }
                else if (k == bc)
                {
                    b++;
                }
            }
            k++;
        }
    }
    cout << r << " " << b << " " << y << " " << g;

    return 0;
}