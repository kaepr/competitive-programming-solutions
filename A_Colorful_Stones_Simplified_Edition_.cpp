#include <bits/stdc++.h>
using namespace std;
int main(){
    int pos=1;
    string s;
    cin>>s;
    string t;
    cin>>t;
    int sp=0;
    for(int i=0; i<t.length(); i++){
        if(s[sp]==t[i]){
            sp++;
            pos++;
        }
    }
    cout<<pos;
    return 0;
}