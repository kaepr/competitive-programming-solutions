#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n < 6)
    {
        cout << n << "\n";
        return 0;
    }

    //4,8,15,16,23,42
    int cnt = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int elm = a[i];
        if (elm == 4)
        {
            mp[4]++;
        }
        if (elm == 8)
        {
            int cnt8 = mp[8];
            if (cnt8 + 1 <= mp[4])
            {
                mp[8]++;
            }
            else
            {
                cnt++;
            }
        }
        if (elm == 15)
        {
            int cnt15 = mp[15];
            if (cnt15 + 1 <= mp[8])
            {
                mp[15]++;
            }
            else
            {
                cnt++;
            }
        }

        if (elm == 16)
        {
            int cnt16 = mp[16];
            if (cnt16 + 1 <= mp[15])
            {
                mp[16]++;
            }
            else
            {
                cnt++;
            }
        }
        if (elm == 23)
        {
            int cnt23 = mp[23];
            if (cnt23 + 1 <= mp[16])
            {
                mp[23]++;
            }
            else
            {
                cnt++;
            }
        }
        if (elm == 42)
        {
            int cnt42 = mp[42];
            if (cnt42 + 1 <= mp[23])
            {
                mp[42]++;
            }
            else
            {
                cnt++;
            }
        }
    }

    int least = mp[42];
    // cout << least << "\n";
    for (auto x : mp)
    {
        cnt += x.second - least;
    }

    cout << cnt << "\n";

    return 0;
}