#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    vector<int> dp(n,0);
    for(int i=0; i<n; i++)
        cin>>v[i];
    
    for(int i=1; i<n-1; i++){
        if(v[i] > v[i-1] && v[i] > v[i+1])
            dp[i]++;
    }
    for(int i=1; i<n; i++)
        dp[i] +=dp[i-1];
    
    int ans =0,max=0;
    for(int i=k-1; i<n; i++){
        int cur = dp[i-1] - dp[i - (k-1)];
        if(cur>max){
            max = cur;
            ans = i - (k - 1);
        }
    }
    cout<<max+1<<" "<<ans+1<<"\n";
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