#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

vector<ll> calc(vector<ll> a){
    ll n = a.size();
    vector<ll> res(n+1);
    ll i=0;
    while(i < n){
        if(a[i]==0){
            i++;
            continue;
        }
        int j = i;
        while(j<n && a[j]==1)
            j++;
        
        for(ll len = 1; len<=j-i; len++)
            res[len] += j - i - len + 1;
        
        i = j;
    }
    return res;
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    vector<ll> b(m);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

     for(int i=0; i<m; i++){
        cin>>b[i];
    }

    
    ll ans = 0;
    auto fa = calc(a);
    auto fb = calc(b);

    for(ll i=1; i<fa.size(); i++){
        if(k%i==0 && k/i <=m){
            ans += fa[i] * fb[k/i];
        }
    }
    cout<<ans<<"\n";

    return 0;
}