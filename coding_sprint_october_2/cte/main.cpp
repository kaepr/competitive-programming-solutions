#include <bits/stdc++.h>
using namespace std;
int main(){
    int q,fn,f;
    scanf("%d",&q);
    while(q>0){
        int n;
        scanf("%d",&n);
        int arr[n][n];
        int min=-1232,ans,a=0;
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                arr[i][j] = i+j;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                a  = n - arr[i][j];
                if(a == 0){
                    ans = 0;
                    fn = 0;
                    f=1;
                }
                if(a < 0){
                    int b = abs(a);
                    if(b < min){
                        min = b;
                        ans = min;
                    }
                }
            }
        }
        if(f==1){
            printf("%d\n",fn);
        }else{
            printf("%d\n",ans);
        }
        q--;
    }
    return 0;
}