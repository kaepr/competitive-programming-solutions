#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,sum=0;
    scanf("%lld",&n);
    long long a[n+1],b[n+1];
    a[0] = 0;
    b[0] = 0;
    for(long long i=1; i<=n; i++)    
        scanf("%lld",&a[i]);
    
    for(long long i=1; i<=n; i++)
        scanf("%lld",&b[i]);
    
    for(long long i=1; i<=n; i++){
        for(long long j=1; j<=n; j++){
            if(i==j){
                sum = a[i];
            }else if(i<j){
                if((j-i)==1){
                    sum = a[i] + a[j];
                }else{
                    long long num,sumb=0;
                    num = j - i - 1;
                    long long c=i;
                    for(long long a=0; a<num; a++){
                        sumb += b[c+1];
                        c++;
                    }
                    sum = a[i] + a[j] + sumb;
                }
            }else if(i>j){
                long long as = n-i+1,assum=0,ac=i;
                for(long long d=0;d<as;d++){
                    assum += b[ac+1];
                    ac++;
                }
                long long bs=j,bssum=0;
                for(long long e=1; e<bs; e++){
                    bssum += b[e];
                }
                sum = a[i] + a[j] + assum + bssum;
            }
        }
    }
    cout << "ans is " << sum << endl;

    return 0;
}