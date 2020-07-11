#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int co=0,ce=0;
    for(int i=0; i<n; i++){
        if(a[i]%2==0)
            ce++;
        else
            co++;
    }

    if(co==n || ce==n){
        for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
    }else{
        sort(a,a+n);
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
    }




      
    return 0;
}