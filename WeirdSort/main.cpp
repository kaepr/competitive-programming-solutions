#include <bits/stdc++.h>
using namespace std;;
using ll = long long;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int m,n;
        //n is number of elements in a
        //m is number of elements in p
        scanf("%d%d",&n,&m);
        int a[n];
        int b[n];
        int p[m];
        int pc[m];
        for(int i=0; i<n; i++){
            int z;
            cin>>z;
            a[i] = z;
            b [i] = z;
        }
        for(int i=0; i<m; i++){
            int x;
            cin >> x;
            p[i] = x - 1;
            pc[i] = x - 1;
        }
            

        

    }
    return 0;
}