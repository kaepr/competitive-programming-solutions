#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;


int main()
{
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    int n;
    cin>>n;
    ans = n-1;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    for(int i=n-2; i>=0; i--){
        if(a[i+1] > a[i])
            ans = i;
        else
            break;
    }
    cout<<ans<<"\n";

    

    return 0;
}