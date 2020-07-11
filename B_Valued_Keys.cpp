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

    string s1,s2,s3;
    cin>>s1>>s2;
    for(int i=0; i<s1.length(); i++){
        if(s1[i]==s2[i])
            s3.push_back(s1[i]);
        else if(s1[i] > s2[i])
            s3.push_back(min(s1[i], s2[i]));
        else{
            cout<<"-1";
            return 0;
        }
    }
    cout<<s3;
    return 0;
}