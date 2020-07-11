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

    string s;
    cin>>s;

    char max = 'a';

    for(int i=0; i<s.length(); i++){
        if(s[i] > max){
            max = s[i];
        }
    }

    int times=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==max)
            times++;
    }
    for(int i=0; i<times; i++){
        cout<<max;
    }
    
      
    return 0;
}