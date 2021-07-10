#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int l=0,r=0;
    int n,m;
    cin>>n>>m;
    cin>>l>>r;
    n--;
    int f=0;
    while(n > 0){
        int nl,nr=0;
        cin>>nl>>nr;
        if(nl <= r){
            r = max(nr,r);
            l = min(l,nl);
            if( l<= m && m<=r){
                f = 1;
            }
        }else if(nl > r){
            f = 0;
            break;
        }
        n--;
    }
    if(l==1){
        cout<<"NO\n";
    }else if(f || (l<=m && m<=r)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

    return 0;
}