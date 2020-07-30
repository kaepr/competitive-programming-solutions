#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll binaryToDecimal(vector<int> n)
{
    ll dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    ll base = 1;

    ll len = n.size();
    for (ll i = len - 1; i >= 0; i--)
    {
        if (n[i] == 1)
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

ll solve2(ll x, ll y)
{
    vector<ll> xbit;
    vector<ll> ybit;
    while (x > 0)
    {
        xbit.push_back(x % 2);
        x /= 2;
    }
    while (y > 0)
    {
        ybit.push_back(y % 2);
        y /= 2;
    }
    reverse(xbit.begin(), xbit.end());
    reverse(ybit.begin(), ybit.end());

    // for(auto it : xbit){
    //     cout<<it<<" ";
    // }
    // cout<<"above number is x\n";

    // for(auto it : ybit){
    //     cout<<it<<" ";
    // }
    // cout<<"above number is y\n";

    vector<int> xplusy;
    for (auto it : xbit)
    {
        xplusy.push_back(it);
    }

    for (auto it : ybit)
    {
        xplusy.push_back(it);
    }

    // for(auto it : xplusy){
    //     cout<<it<<" ";
    // }
    // cout<<"\nabove number is xplusy\n";

    vector<int> yplusx;
    for (auto it : ybit)
    {
        yplusx.push_back(it);
    }

    for (auto it : xbit)
    {
        yplusx.push_back(it);
    }

    // for(auto it : yplusx){
    //     cout<<it<<" ";
    // }
    // cout<<"\nabove number is yplusx\n";

    ll xpy = 0;
    ll ypx = 0;
    int base = 1;
    reverse(xplusy.begin(), xplusy.end());

    for (int i = 0; i < xplusy.size(); i++)
    {
        if (xplusy[i] == 1)
            xpy += base;
        base *= 2;
    }
    //cout << "xpy is " << xpy << "\n";
    base = 1;
    reverse(yplusx.begin(), yplusx.end());

    for (int i = 0; i < yplusx.size(); i++)
    {
        if (yplusx[i] == 1)
            ypx += base;
        base *= 2;
    }
    //cout << "ypx is " << ypx << "\n";
    return xpy - ypx;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = -1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //cout<<"concat of "<<a[i]<<" "<<a[j]<<"\n";
            if(a[i]!=a[j])
                ans = max(ans, solve2(a[i], a[j]));
        }
    }

    cout << ans << "\n";
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