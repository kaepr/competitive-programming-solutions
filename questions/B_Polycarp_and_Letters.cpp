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
    string s;
    cin >> s;
    // set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        int cnt = 0;
        set<char> temp;
        if (isupper(s[i]))
        {
            continue;
        }
        temp.insert(s[i]);

        for (int j = i + 1; j < n; j++)
        {
            if (isupper(s[j]))
            {
                break;
            }
            temp.insert(s[j]);
        }
        // for(auto x : temp){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        ans = max(ans, (int)temp.size());
    }
    cout << ans << "\n";

    return 0;
}