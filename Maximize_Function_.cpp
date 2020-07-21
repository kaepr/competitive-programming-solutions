#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll a[100001];
ll n, k;

ll S(ll x)
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += max(a[i] - i * x, (ll)0);
    return res;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    ll l=0,r=1e13;
    ll ans =0,sum=0;
    while(l<=r){
        ll mid = l + (r - l)/2;
        ll temp = S(mid);
        if(temp>=k){
            ans = mid;
            sum = temp;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout<<ans<<" "<<sum<<"\n";
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

/*


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll a[100005];
ll n,k;

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll S(ll x){
    ll res = 0;
    for(int i=0; i<n; i++)
        res += max(a[i] - i*x, (ll) 0);
    return res;
}

void solve()
{
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    
    ll l=0,r = 1e12;
    ll s = k,res;
    while(l<=r){
        ll mid = (l + r)/2;
        ll y = S(mid);
        if(y<k)
            r = mid - 1;
        else
            if(S(mid) + 1 < k){
                s = y;
                res = mid;
                break;
            }else
                l = mid + 1;
    }
    cout<<res<<" "<<s<<"\n";
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


*/