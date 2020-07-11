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

    int c[5];
    for(int i=0; i<5; i++)
        cin>>c[i];
    
    int sum = 0;
    for(int i=0; i<5; i++){
        sum += c[i];
    }

    if(sum==0 || sum%5!=0){
        cout<<"-1";
    }else{
        cout<<sum/5;
    }

    
       
    return 0;
}