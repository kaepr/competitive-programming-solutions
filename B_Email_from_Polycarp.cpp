#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string a, b;
    cin >> a >> b;
    int alen = (int)a.size();

    int blen = (int)b.size();
    if (alen > blen)
    {
        puts("NO");
        return;
    }
    vector<pair<char, int>> v1, v2;
    for (int i = 0; i < alen; i++)
    {
        int cnt = 0;
        int j = i;
        while (j < alen)
        {
            if (a[i] != a[j])
                break;
            cnt++;
            j++;
        }
        v1.emplace_back(a[i], cnt);
        i = j - 1;
    }

    a = b;
    alen = blen;
    for (int i = 0; i < alen; i++)
    {
        int cnt = 0;
        int j = i;
        while (j < alen)
        {
            if (a[i] != a[j])
                break;
            cnt++;
            j++;
        }
        v2.emplace_back(a[i], cnt);
        i = j - 1;
    }

    alen = v1.size();
    blen = v2.size();
    if (alen != blen)
    {
        puts("NO");
        return;
    }

    for (int i = 0; i < alen; i++)
    {
        if (v1[i].first != v2[i].first)
        {
            puts("NO");
            return;
        }
        if (v1[i].second > v2[i].second)
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while (n > 0)
    {
        solve();
        n--;
    }

    return 0;
}