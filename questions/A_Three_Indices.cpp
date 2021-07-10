#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int aa = 0, bb = 0, cc = 0;
    int f = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        //elements before i
        vector<int> smaller;
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                smaller.push_back(j);
            }
        }
        if (smaller.size() == 0)
        {
            continue;
        }

        vector<int> greater;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j])
            {
                greater.push_back(j);
            }
        }

        if (greater.size() == 0)
        {
            continue;
        }

        if (smaller.size() != 0 && greater.size() != 0)
        {
            aa = smaller[0];
            bb = i;
            cc = greater[0];
            f = 1;
        }
        if(f)
            break;
    }
    if (f){
        cout<<"YES\n";
        cout<<aa<<" "<<bb<<" "<<cc<<"\n";
    }else{
        cout<<"NO\n";
    }
}

int main()
{
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