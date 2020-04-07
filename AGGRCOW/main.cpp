#include<bits/stdc++.h>

using namespace std;

 

bool ok(int ar[], int n, int given_cows, int x){
    int cows = 1 , current_distance = 0; //first cow is placed in the left most stall
    for(int i=1; i<n; i++){
        if(current_distance + ar[i] - ar[i-1] <= x) current_distance += ar[i] - ar[i-1];
        else cows++, current_distance = 0; //assigning another cow in the stalls
    }
    return (cows >= given_cows); //returns if cows needed for x is greater than or equal to the given number of cows to place or not

}

 

int main(){
    int t, n, c , lo, mid, hi;
    cin>>t;
    while(t--){
        cin>>n>>c;
        int ar[n];
        for(int i=0; i<n; i++) cin>>ar[i];
        sort(ar, ar+n);
        lo = 0; //minimum distance between two cows can be at least 0
        hi = ar[n-1] - ar[0]; //maximum difference between two cows can be at most the difference between first and last stall where cows are placed
        int ans = 0;
        while(lo<=hi){
            mid = (hi+lo)/2;
            if(ok(ar, n, c, mid)) ans = mid, lo = mid+1; //if number of cows for x is greater than or equal to c, then we have to increase the lower bound. because X is inversly propotional to C and we are finding maximum X
            else hi = mid-1; //as cows for x is less then c, reducing the higher bound
        }
        cout<<ans+1<<endl;
    }
    return 0;
}