#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    int pos[n];
    map<int, int> mapp;
    set<int> light_pos;
    set<pair<int, int>> inter;
    inter.insert({0, x});
    set<array<int,2>> segments = {{0,x}};
    //for (auto itr = inter.begin(); itr != inter.end(); ++itr)
    //{
     //   cout << (*itr).first << " " << (*itr).second << "\n";
    //}
    multiset<int> lengths;
    lengths.insert(x-0);
    for (int i = 0; i < n; i++)
    {
        //new light to added here
       int temp;
       cin>>temp;
        //cout << pos[i] << "\n";
        auto itr = segments.upper_bound({temp,temp});
        itr--;
        auto curr = *itr;
        //itr++;
        //cout <<  (*itr).first << " " << (*itr).second  << "\n";
        //inter.erase(*itr)
        lengths.erase(lengths.find(curr[1] - curr[0]));
        segments.erase(curr);

        //cout<<temp - left<<" yeah\n";
        segments.insert({curr[0], temp});

        lengths.insert(temp - curr[0]);

        lengths.insert(curr[1] - temp);

        //cout<<right - temp<<" yeah\n";

        

        segments.insert({temp, curr[1]});

        //for(auto it = lengths.begin(); it!= lengths.end(); it++){
        //    cout<<"length is "<<*it<<"\n";
        //}
        

        cout<<*lengths.rbegin()<<" ";

    }

    return 0;
}


/*
int x,n;
    cin>>x>>n;
    int pos[n];
    map<int, int> mapp;
    set<int> light_pos;
    set<pair<int,int>> inter;
    inter.insert({0,x});
    set <pair<int, int>> :: iterator itr;
    for(itr= inter.begin(); itr!= inter.end(); ++itr){
        cout<<itr->first << " " << itr->second<<"\n";
    }
    set<int> lengths;



    light_pos.insert(0);
    light_pos.insert(x);
    for(int i=0; i<n; i++){
        //new light to added here
        cin>>pos[i];
        cout<<pos[i]<<"\n";
        itr = inter.upper_bound({pos[i], pos[i]});
        cout<<itr->first << " " << itr->second<<"\n";
        cout<<inter(itr);

    }
*/