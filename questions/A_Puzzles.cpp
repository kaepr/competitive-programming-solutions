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

    int n,m;
    cin>>n>>m;
    int diff = 1e9;
    int a[m];
    for(int i=0; i<m; i++)  
        cin>>a[i];
    
    sort(a,a+m);
    int ptr = 0,ptr2 = n-1;
    while(ptr2<m){
        int diff2 = a[ptr2] - a[ptr];
        diff = min(diff2,diff);
        ptr2++;
        ptr++;
    }
    cout<<diff;
       
    return 0;
}