#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    map<char, int> lastPos;
    set<char> active;

    for(int i=0; i<n; i++)
        lastPos[s[i]] = i;
    
    for(int i=0; i<n; i++){
        active.insert(s[i]);
        if(active.size() > k){
            cout<<"YES\n";
            return 0;
        }
        if(lastPos[s[i]] == i)
            active.erase(s[i]);
    }
    cout<<"NO\n";
    return 0;
}