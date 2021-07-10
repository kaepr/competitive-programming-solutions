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
    int ans = n/2 + 1;

    cout<<ans<<"\n";
    for(int i=1; i<=ans; i++)
        printf("\n%d 1",i);
    for(int i=2; i<= n - ans + 1; i++)
        printf("\n%d %d",ans, i);
      
    return 0;
}