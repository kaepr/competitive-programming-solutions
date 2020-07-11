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

    int n;
    cin >> n;
    string s;
    int x = 0, y = 0;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
        {
            ++y;
        }
        else if (s[i] == 'D')
        {
            --y;
        }
        else if (s[i] == 'L')
        {
            --x;
        }
        else if (s[i] == 'R')
        {
            ++x;
        }
    }

    int val1 = abs(x) + abs(y);
    cout << n - val1;
    return 0;
}