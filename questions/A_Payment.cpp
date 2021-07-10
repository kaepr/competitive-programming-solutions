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

    if(n%1000==0){
        cout<<0<<"\n";
    }else{
        cout<< 1000 - n%1000;
    }
      
    return 0;
}