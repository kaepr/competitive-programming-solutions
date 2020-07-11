#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool sortinrev(const pair<int,int> &a, const pair<int,int> &b){
    return (a.first > b.first);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int,int>> a;
    int n,s;
    cin>>n>>s;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        a.emplace_back(x,y);
    }
    int t=0;
    sort(a.begin(), a.end(), sortinrev);

    int last = 0;

    for(auto i : a){
        t += s - i.first;
        s = i.first;
        last = s;
        //cout<<"time right now is"<<t<<"\n";
        if(t >= i.second){
            //do nothing
        }else{
            int diff = i.second - t;
            //cout<<" time to wait foe new people"<<diff<<"\n";
            t += diff;
        }
        //cout<<"time ryes yes is "<<t<<"\n";
    }
    cout<<t + last<<"\n";
      
    return 0;
}