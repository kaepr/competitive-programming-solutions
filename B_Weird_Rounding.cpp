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

    ll n,k;
    cin>>n>>k;
    ll yes = n;
    ll copy = n;
    ll num_digits=0;
    while(copy>0){
        num_digits++;
        copy/=10;
    }
    ll w=0;
    int num=0;
    int zeros=0;
    while(zeros<k){
        ll lastDigit = n%10;
        if(lastDigit==0){
            zeros++;
        }else{
            w++;
        }
        n=n/10;
    }

    
    if(yes==0){
        cout<<0<<"\n";
    }else if(n>0){
         cout<<w<<"\n";
    }else{
        cout<<num_digits-1<<"\n";
    }
        
      
    return 0;
}