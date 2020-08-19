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

    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 1; i <= n; i++)
        {
            a.push_back(i);
        }
        reverse(a.begin(), a.end());
        for (auto x : a)
        {
            cout << x << " ";
        }
        cout << "\n";
        t--;
    }

    return 0;
}