#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int,int> level;

struct play{
    int p,c;
}; 

int main(){
    int t;
    cin>>t;
    while(t>0){
        ll n,x;
        cin>>n>>x;
        ll arr[n];
        int flag=1;
        for(ll i=0; i<n; i++){
            cin>>arr[i];
        }

        sort(arr,arr+n, greater<>());
        ll extra_money=0;
        for(ll i=0; i<n; i++){
            if(arr[i] > x){
                extra_money = extra_money + arr[i] - x;
            }
        }

        for(ll i=0; i<n; i++){
            if(arr[i] < x && extra_money -(x - arr[i]) >= 0){
                extra_money = extra_money - (x - arr[i]);
                arr[i] = arr[i] + x - arr[i];
            }
        }

        ll cnt=0;
        for(ll i=0; i<n; i++){
            if(arr[i] >= x){
                cnt++;
            }
        }

        cout<<cnt<<"\n";

        //cout<< "t number is " << t << "\n";

        t--;
    }
    return 0;
}