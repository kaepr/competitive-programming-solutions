#include <bits/stdc++.h>
using namespace std;
int ans[1000][1000];

int calc(int spo,int swe,int cou){
    if(cou<0)
        return 0;

    if(cou!=0)
        return calc(spo+1,swe,cou-1) + calc(spo,swe+1,cou-1);

    if(cou==0){
        if(spo>swe)
            if(ans[spo][swe] != 1){
                ans[spo][swe] = 1;
            }
            
    }
    return 0;
}

int main(){
    int t;
    scanf("%d",&t);
    int spo,swe,cou,z=0;
    int aaa[t];
    while(t>0){
        scanf("%d%d%d",&spo,&swe,&cou);
        int b = calc(spo,swe,cou);
        int a;
        for(int i=0; i<1000; i++){
            for(int j=0; j<1000; j++){
                if(ans[i][j]==1){
                    a++;
                }
            }
        }
        aaa[z] = a;
        z++;
        t--;
    }
    for(int i=0; i<t; i++){
        printf("%d\n",aaa[i]);
    }
    return 0;
}