#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> level;

struct play{
    int p,c;
}; 

int main(){
    int t;
    cin>>t;
    while(t--){
       int n,flag=1;
       cin>>n;
       level levels[n];
       for(int i=0; i<n; i++){
            cin>>levels[i].first>>levels[i].second;
            
            if(i>0){
                int dif2 = levels[i].second - levels[i-1].second;
                int dif1 = levels[i].first - levels[i-1].first;

                if(levels[i].first < levels[i-1].first)
                    flag=0;

                if(levels[i].second < levels[i-1].second)
                    flag=0;

                if(dif2>dif1)
                    flag=0;
            }

            if(levels[i].second > levels[i].first)
                flag=0;
       }
        if(flag==0){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}