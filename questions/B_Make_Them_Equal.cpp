#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    set<int> elms;
    for(int i=0; i<n; i++)
        elms.insert(a[i]);
    
    vector<int> dist;
    for(auto it : elms)
        dist.push_back(it);
    
    if(dist.size() > 3){
        cout<<-1<<"\n";
    }else if(dist.size()==3){
        if(dist[2] - dist[1] == dist[1] - dist[0])
            cout<<dist[2] - dist[1]<<"\n";
        else
            cout<<-1<<"\n";
    }else if(dist.size()==1){
        cout<<"0\n";
    }else{
        if((dist[1] - dist[0])%2==0){
            cout<<(dist[1] - dist[0])/2<<"\n";
        }else{
            cout<<dist[1] - dist[0]<<"\n";
        }
    }

    return 0;
}