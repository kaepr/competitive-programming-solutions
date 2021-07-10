#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int time = 0;
    while (1)
    {
        int current = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
                current++;
        }

        //convert them
        string s2 = s;
        //cout<<s2<<"\n";

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'A' && s[i + 1] == 'P')
                s2[i + 1] = 'A';
        }

        int newTotal = 0;
        for (int i = 0; i < n; i++)
        {
            if (s2[i] == 'A')
                newTotal++;
        }

        // if(time==n){
        //     break;
        // }
        if (newTotal == current || newTotal == n)
        {
            if (s2 == s)
            {
                break;
            }
            else
            {
                time++;
                break;
            }
        }
        time++;
        s = s2;
    }
    cout << time << "\n";
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