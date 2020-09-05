#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    // to determine if second word could be printed by tping the first one
    vector<pair<char, int>> g1;
    vector<pair<char, int>> g2;
    for (int i = 0; i < s1.length(); i++)
    {
        char c = s1[i];
        int cnt = 1;
        int ptr = i + 1;
        while (true)
        {
            if (s1[ptr] == c)
            {
                cnt++;
                ptr++;
            }
            else
            {
                break;
            }
        }
        g1.push_back(make_pair(c, cnt));
        i = ptr - 1;
    }

    for (int i = 0; i < s2.length(); i++)
    {
        char c = s2[i];
        int cnt = 1;
        int ptr = i + 1;
        while (true)
        {
            if (s2[ptr] == c)
            {
                cnt++;
                ptr++;
            }
            else
            {
                break;
            }
        }
        g2.push_back(make_pair(c, cnt));
        i = ptr - 1;
    }

    //  for (auto x : g1)
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }
    // cout<<"break case\n";

    //  for (auto x : g2)
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }
    // cout<<"break case\n";

    bool flag = true;
    int ptr = 0;
    for (int i = 0; i < g1.size(); i++)
    {
        if (g1[i].first == g2[ptr].first && g1[i].second <= g2[ptr].second)
        {
            ptr++;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    // cout<<ptr<<"\n";
    // cout<<g2.size()<<"\n";
    if(ptr == g2.size()){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    // if(ptr + 1 != g2.size()){
    //     cout<<"NO\n";
    //     return;
    // }

    // cout << "YES\n";

   
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