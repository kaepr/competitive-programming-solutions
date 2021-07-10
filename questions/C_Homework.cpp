#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

bool cmp(pair<char, int> &a, pair<char, int> &b)
{
    return a.second < b.second;
}

struct letter
{
    char c;
    int pos;
    int cnt = 0;
};

map<char, int> mp;

bool compare(char a, char b)
{
    if (mp[a] == mp[b])
        return a < b;
    return mp[a] > mp[b];
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, bs;
    int k, cnt = 0;
    cin >> s >> k;
    bs = s;

    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    sort(s.begin(), s.end(), compare);
    cout << s << "\n";

    for (int i = 0; i < (int)s.length() - k; i++)
        mp[s[i]] = 0;

    for(auto x : mp){
        cout<<x.first<<" "<<x.second<<"\n";
    }

    for (auto it : mp)
        if (!it.second)
            cnt++;

    cout << cnt << endl;

    for (int i = 0; i < s.length(); i++)
        if (!mp[bs[i]])
            cout << bs[i];

    cout << endl;

    return 0;
}