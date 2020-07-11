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
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    for(int i=0; i<t; i++){
        for(int i=0; i<n-1; i++){
            if(s[i]=='B' && s[i+1]=='G'){
                s[i]='G';
                s[i+1]='B';
                i++;
            }
        }
    }
    cout<<s;
    return 0;
}