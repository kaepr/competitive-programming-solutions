#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int move = 1;
    int poss = 1;
    while (s.length() > 0 && poss)
    {
        poss = 0;
        int i=0;
        for (i = 0; i < s.length() - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                move++;
                poss = 1;
                break;
            }
        }
        if (poss)
        {
            s.erase(i, 2);
        }
    }

    if (move % 2 != 0)
    {
        cout << "NET\n";
    }
    else
    {
        cout << "DA\n";
    }

    //cout << "new case\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve2(int a, int b, int c)
{
    int n = 1;
    ll s1 = 0;
    ll s2 = 0;
    while (n < 100000)
    {
        n++;
        s1 = a * n;

        if (n % b == 0)
        {
            s2 = n / b * c;
        }
        else if (b > n)
        {
            s2 = c;
        }
        else
        {
            s2 = (n / b + 1) * c;
        }

        if (s2 < s1)
            return n;
    }
    return -1;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;


    if (a < c)
    {
        cout << "1 ";
    }
    else
    {
        cout << "-1 ";
    }

    if (a == c)
    {
        cout << b << "\n";
    }
    else
    {
        cout << solve2(a, b, c) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
*/