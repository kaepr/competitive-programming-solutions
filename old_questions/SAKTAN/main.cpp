#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        long long n,m,q;
        scanf("%lld%lld%lld",&n,&m,&q);
        long long arrx[n],arry[m];
        for(long long i=0; i<n; i++){
            arrx[i] = 0;
        }
        for(long long i=0; i<m; i++){
            arry[i] = 0;
        }
        for(long long i=0; i<q; i++){
            long long x,y;
            scanf("%lld%lld",&x,&y);
            x = x - 1;
            y = y - 1;
            if(i == 0){
                arrx[x] = arrx[x] + 1;
                arry[y] = arry[y] + 1;
            }else if(i%2 != 0){
                arrx[x] = arrx[x] - 1;
                arry[y] = arry[y] - 1;
            }else if(i%2 == 0){
                arrx[x] = arrx[x] + 1;
                arry[y] = arry[y] + 1;
            }

        }
        long long nodd=0,onex=0,oney=0;
        for(long long i=0; i<n; i++){
            if(abs(arrx[i])==1)
                onex++;
        }
        for(long long i=0; i<m; i++){
            if(abs(arry[i])==1)
                oney++;
        }
        /*
        for(long long i=0; i<n; i++){
            printf("%lld ",arrx[i]);
        }
        printf("\n");
        for(long long i=0; i<m; i++){
            printf("%lld ",arry[i]);
        }
        */
        nodd = onex + oney;
        printf("%lld\n",nodd);
        t--;
    }
    return 0;
}