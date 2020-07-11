#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin>>s;
    int inf = 1e9;
    ll res = 0;
    for(ll i=0; i<=1e9; i++){
        ll cur = 0;
        bool ok = true;
        for(ll j=1; j<=s.length(); j++){
            res++;
            if(s[j]=='+')
                cur++;
            else
                cur--;
            
            if(cur<0)
                ok = false;
                break;
        }
        if(ok)
            break;
    }
    cout<<res<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }   
    return 0;
}