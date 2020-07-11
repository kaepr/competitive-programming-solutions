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

    string s,t;
    cin>>s>>t;
    int cnt=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]!=t[i])
            cnt++;
    }
    cout<<cnt<<"\n";
      
    return 0;
}