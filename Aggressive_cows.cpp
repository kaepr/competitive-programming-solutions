#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int N,C;


bool chk(int x){
    int cows_placed = 1, last_pos = arr[0];

    for(int i=1; i<N; i++){
        if((arr[i] - last_pos) >= x){
            if(++cows_placed == C){
                return true;
            }
            last_pos = arr[i];
        }
    }
    return false;
}


void solve(){
    cin>>N>>C;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr, arr+N);

    int low=0,high=1e9,mid,pos=0;
    while(high>=low){
        mid = (high + low)/2;

        if(chk(mid)){
            low = mid + 1;
            pos = mid;
        }else{
            high = mid -1;
        }
    }
    cout<<pos<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}