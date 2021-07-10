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

    int a,b,s;
    cin>>a>>b>>s;
    //minimum steps to take
    if(s>=(abs(a)+abs(b)) && (s - (abs(a) + abs(b)))%2==0){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
      
    return 0;
}