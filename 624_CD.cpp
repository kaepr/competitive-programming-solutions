#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int n, num, sum = 0;
vector<int> track, cur;
vector<vector<int>> ans;
vector<bool> vis;
map<int, int> mp;
int pos = 0;

void backtrack(int sum, int idx)
{
    for (int i = idx; i < num; i++)
    {
        if (vis[i])
            continue;

        if (sum + track[i] <= n)
        {
            cur.push_back(track[i]);
            vis[i] = true;
            backtrack(sum + track[i], i + 1);
            vis[i] = false;
            cur.erase(cur.begin() + cur.size() - 1);
        }
    }
    if (cur.size() && mp.find(sum) == mp.end())
    {
        mp[sum] = pos;
        ans.push_back(cur);
        pos++;
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n)
    {
        cin >> num;
        track.resize(num);
        vis.assign(num, false);
        cur.clear();
        ans.clear();
        mp.clear();

        for (int i = 0; i < num; i++)
        {
            int x;
            cin >> x;
            track.push_back(x);
        }

        sum = 0, pos = 0;
        backtrack(0, 0);
        auto g = mp.rbegin();
        for (auto i : ans[g->second])
        {
            cout << i << " ";
        }
        cout << "sum: " << g->first << "\n";
    }

    return 0;
}