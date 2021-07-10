#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), lengths;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            continue;

        int ptr = i;
        while ((ptr + 1) < n && (a[ptr + 1] == 0))
        {
            ptr++;
        }
        lengths.push_back(ptr - i + 1);
        i = ptr;
    }

    if (lengths.size() == 0)
    {
        cout << "No\n";
    }
    else if (lengths.size() == 1)
    {
        if (lengths[0] % 2 == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        int maxLen = 0, id = -1;
        int m = lengths.size();
        for (int i = 0; i < m; i++)
        {
            if (maxLen < lengths[i])
            {
                maxLen = lengths[i];
                id = i;
            }
        }
        swap(lengths[0], lengths[id]);
        maxLen = 0;
        id = -1;
        for (int i = 1; i < m; i++)
        {
            if (maxLen < lengths[i])
            {
                maxLen = lengths[i];
                id = i;
            }
        }
        swap(lengths[1], lengths[id]);

        if ((lengths[0] % 2) && (lengths[1] <= ((lengths[0] - 1) / 2)))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
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