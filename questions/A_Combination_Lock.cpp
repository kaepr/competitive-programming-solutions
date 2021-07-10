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

    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i]));
    }
    cout<<ans;
       
    return 0;
}