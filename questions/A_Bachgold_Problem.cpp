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
    if(n%2==0){
        cout<<n/2<<"\n";
        while(n>0){
            cout<<2<<" ";
            n-=2;
        }
    }else{
        cout<<(n-3)/2 + 1<<"\n";
        while(n!=3){
            cout<<2<<" ";
            n-=2;
        }
        cout<<3;
    }
     
    return 0;
}