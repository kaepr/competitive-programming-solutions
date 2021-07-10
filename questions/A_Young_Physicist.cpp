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
    int ans=0;
    int a=0,b=0,c=0;
    for(int i=0; i<n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        a+=x;
        b+=y;
        c+=z;
    }
    if(a==0 && b==0 && c==0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
      
    return 0;
}