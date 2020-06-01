#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<bool> used(n + 1);
    int t = n;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        used[x] = true;

        vector<int> v;
        while (t >= 1 && used[t])
            v.push_back(t--);

        if (v.empty())
            cout << "\n";
        else
        {
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " \n"[i + 1 == v.size()];
        }
    }

    return 0;
}