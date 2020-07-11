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
    vector<pair<int,int>> rooms;
    int poss=0;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        if(b - a >=2){
            poss++;
        }
    }
    cout<<poss;
       
    return 0;
}