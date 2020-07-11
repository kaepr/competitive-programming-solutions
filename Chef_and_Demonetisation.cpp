#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll s,n;
    cin>>s>>n;
    if(s==n){
        cout<<1<<"\n";
    }else if(n>s){
        if(s==1){
            cout<<"1\n";
        }else if(s%2==0){
            cout<<1<<"\n";
        }else if(s%2!=0){
            cout<<2<<"\n";
        }
    }else if(s>n){
        if(s%2==0){ 
            if(s%n==0){
                cout<<s/n<<"\n";
            }else{
                cout<<s/n + 1<<"\n";
            }
        }else if(s%2!=0){
            ll rem = s%n;
            ll toAdd=0;
            if(rem==1 || rem%2==0){
                toAdd = 1;
            }else{
                toAdd = 2;
            }  
            cout<<s/n + toAdd<<"\n";
        }
    }
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