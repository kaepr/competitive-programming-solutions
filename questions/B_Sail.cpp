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

    int t, sx, sy, ex, ey;
    cin >> t >> sx >> sy >> ex >> ey;
    string s;
    cin >> s;
    int flag = 0;
    int final_time = 0;
    for (int i = 0; i < t; i++)
    {
        if (s[i] == 'N')
        {
            sy++;
        }
        else if (s[i] == 'S')
        {
            sy--;
        }
        else if (s[i] == 'W')
        {
            sx--;
        }
        else if(s[i]=='E')
        {
            sx++;
        }

        if (sx == ex && sy == ey)
        {
            final_time = i + 1;
            flag = 1;
        }
    }

    if (flag)
    {
        cout << final_time << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}