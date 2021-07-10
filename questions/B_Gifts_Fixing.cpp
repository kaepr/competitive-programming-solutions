#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    ll n;
    cin>>n;
    ll a[n],b[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];
    
    for(ll i=0; i<n; i++)
        cin>>b[i];
    
    ll a_least = *min_element(a, a+n);
    ll b_least = *min_element(b, b+n);

    ll total = 0;
    for(ll i=0; i<n; i++){
        ll a_diff = a[i] - a_least;
        ll b_diff = b[i] - b_least;
        total+=min(a_diff, b_diff);
        total = total + (a_diff - min(a_diff, b_diff)) + (b_diff - min(a_diff, b_diff));
    }
    cout<<total<<"\n";


    
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