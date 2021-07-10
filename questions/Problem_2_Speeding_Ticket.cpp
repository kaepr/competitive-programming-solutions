#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int,int>> spd(101);
    int n,m;
    cin>>n>>m;
    int ptr = 1;
    int d=0;
    for(int i=0; i<n; i++){
        int x,s;
        cin>>x>>s;
        d+=x;
        for(int j=ptr; j<=d; j++){
            spd[j].first = j;
            spd[j].second = s;
        }
        ptr = d+1;
    }
    vector<pair<int,int>> cow(101);
    ptr= 1;
    d = 0;
    for(int i=0; i<m; i++){
        int x,s;
        cin>>x>>s;
        d+=x;
        for(int j=ptr; j<=d; j++){
            cow[j].first = j;
            cow[j].second = s;
        }
        ptr = d+1;
    }

    int diff = 0;

    for(int i=1; i<=100; i++){
        if(cow[i].second > spd[i].second)
            diff = max(cow[i].second - spd[i].second, diff);
    }
    cout<<diff<<"\n";

    
    return 0;
}