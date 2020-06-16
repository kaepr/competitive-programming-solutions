#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    vector<int> ans;

    for(int i=0; i<n; i++){
        if(i==0 || i==(n-1) || (p[i-1] < p[i]) != (p[i] < p[i+1]))
            ans.push_back(p[i]);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}