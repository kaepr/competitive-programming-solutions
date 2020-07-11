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

    int s,n;
    cin>>s>>n;
    vector<pair<int,int>> dragons;
    for(int i=0; i<n; i++){
        int strength, bonus;
        cin>>strength>>bonus;
        dragons.push_back({strength, bonus});
    }

    sort(dragons.begin(), dragons.end());

    int flag=1;
    for(int i=0; i<n; i++){
        if(s > dragons[i].first){
            s += dragons[i].second;
        }else{
            flag = 0;
        }
    }
    if(flag){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }


     
    return 0;
}