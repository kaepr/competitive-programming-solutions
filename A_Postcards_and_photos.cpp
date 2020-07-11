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
    int result = 0, count =1;
    for(int i=1; i<s.length(); i++){
        if(s[i] == s[i-1])
            count++;
        else{
            result += (count + 4)/5;
            count=1;
        }
    }   
    result += (count + 4)/5;
    cout<<result<<"\n";
    return 0;
}