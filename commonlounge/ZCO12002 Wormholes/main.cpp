/*

*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N=0,X=0,Y=0;
    scanf("%lld",&N);
    scanf("%lld",&X);
    scanf("%lld",&Y);
    long long start[N];
    long long end[N];
    for(long long i=0; i<N; i++){
        scanf("%lld",&start[i]);
        scanf("%lld",&end[i]);
    }
    long long arrX[X],arrY[Y];
    for(long long i=0; i<X; i++){
        scanf("%lld",&arrX[i]);
    }
    for(long long i=0; i<Y; i++){
        scanf("%lld",&arrY[i]);
    }
    int start_size = sizeof(start)/sizeof(start[0]);
    int X_size = sizeof(arrX)/sizeof(arrX[0]);
    sort(start,start+start_size);
    sort(arrX,arrX+X_size);
    for(int i=0; i < N; i++){
        printf("%lld ",start[i]);
    }
    printf("\n");
    for(int i=0; i < X; i++){
        printf("%lld ",arrX[i]);
    }
    return 0;
}