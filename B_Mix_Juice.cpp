#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    int p[n];
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    int ans=0;
    sort(p, p +n);
    for(int i=0; i<k; i++)
        ans+=p[i];

    cout<<ans<<"\n";

    return 0;
}