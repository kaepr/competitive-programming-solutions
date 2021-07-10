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
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }

    vector<pair<int, int>> v;

    auto p = mp.begin();
    int k;
    while (p != mp.end())
    {
        k = p->first;
        if (mp[k].size() == 1)
        {
            v.push_back({k, 0});
        }
        else
        {
            set<int> s;
            for (int i = 1; i < mp[k].size(); i++)
            {
                s.insert(abs(mp[k][i] - mp[k][i - 1]));
            }

            auto q = s.begin();
            if (s.size() == 1)
            {
                v.push_back({k, *q});
            }
        }
        p++;
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}