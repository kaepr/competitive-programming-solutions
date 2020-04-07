#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1; i<n+1; i++)
        cin>>a[i];

    int m;
    cin>>m;
    while(m){
        int x,y;
        cin>>x>>y;
        if(x==1){
            a[x+1] = a[x+1] + a[x] - y;
            a[1] = 0;
        }else if(x==n){
            a[x-1] = a[x - 1]  + y - 1;
            a[n] = 0;
        }else{
            a[x-1] = a[x - 1]  + y - 1;
            a[x+1] = a[x+1] + a[x] - y;
            a[x]=0;
        }
        m--;
    }
    for(int i=1; i<n+1; i++)
        cout<<a[i]<<endl;
    
    return 0;
}