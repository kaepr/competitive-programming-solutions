#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;

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