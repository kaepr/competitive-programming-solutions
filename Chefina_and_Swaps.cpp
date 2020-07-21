#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n], a_copy[n], b_copy[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a_copy[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b_copy[i] = b[i];
    }

    int f_check = 1;
    map<int, int> nums;
    for (int i = 0; i < n; i++)
        nums[a[i]]++;

    for (int i = 0; i < n; i++)
        nums[b[i]]++;

    for (auto i : nums)
    {
        if (i.second % 2 != 0)
        {
            f_check = 0;
        }
    }

    if (f_check == 0)
    {
        cout << "-1\n";
    }
    else
    {
        map<int, int> elms;
        int cost = 0;
        for (int i = 0; i < n; i++)
        {
            elms[a[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            elms[b[i]]++;
        }

        map<int, int> a_cnt;
        for (int i = 0; i < n; i++)
        {
            a_cnt[a[i]]++;
        }

        map<int, int> b_cnt;
        for (int i = 0; i < n; i++)
        {
            b_cnt[b[i]]++;
        }

        vector<int> a_extra;
        vector<int> b_extra;
        for (auto i : a_cnt)
        {
            int num = i.first;
            int times = i.second - (nums[i.first]) / 2;
            for (int i = 0; i < times; i++)
            {
                a_extra.push_back(num);
            }
        }

        for (auto i : b_cnt)
        {
            int num = i.first;
            int times = i.second - (nums[i.first]) / 2;
            for (int i = 0; i < times; i++)
            {
                b_extra.push_back(num);
            }
        }
        if (a_extra.size() == 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            sort(a_extra.begin(), a_extra.end());

            sort(b_extra.begin(), b_extra.end());

            int low = min(a_extra[0], b_extra[0]);
            cost = a_extra.size() * low;

            cout << cost << "\n";
        }
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
