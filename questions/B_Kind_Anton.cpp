#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int b[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        for(int i=0; i<n; i++)
            cin>>b[i];

        int flag=1;
        vector<int> good(2,0);
        for(int i=0; i<n; i++){
            if(a[i] > b[i] && !good[0]){
                flag=0;
            }else if(a[i] < b[i] && !good[1]){
                flag=0;
            }

            if(a[i] == -1)
                good[0] = 1;
            if(a[i] == 1)
                good[1] = 1;
        }
        if(flag){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}