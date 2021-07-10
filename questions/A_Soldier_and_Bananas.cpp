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

    int k,n,w;
    cin>>k>>n>>w;
    int cnt=1;
    int cost=0;
    for(int i=1; i<=w; i++){
        cost += cnt*k;
        cnt++;
    }
    if(cost<=n){
        cout<<"0\n";
    }else{
        cout<<cost - n<<"\n";
    }
       
    return 0;
}