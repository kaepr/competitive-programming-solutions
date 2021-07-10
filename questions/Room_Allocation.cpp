#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    
    //int a[n];
    vector<pair<int,bool>> times;
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        times.push_back({start, true});
        times.push_back({end, false});
    }

    sort(times.begin(), times.end());

    int count[n];
    int ind=0;

    int curr_people=0,people=0;

    for(int i=0; i<times.size(); i++){
         curr_people += times[i].second? 1 : -1;
         //count[ind] = curr_people;
         //ind
         people = max(people, curr_people);
    }
    cout<<people<<"\n";
    // for(int i=0; i<count.size(); i++){
    //     cout<<count[i]<<" ";
    // }

    return 0;
}