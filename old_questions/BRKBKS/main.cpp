#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t)
    {
        int s;
        scanf("%d",&s);
        int w[3];
        for(int i=0; i<3; i++){
            scanf("%d",&w[i]);
        }
        int total = w[0] + w[1] + w[2];
        if(total<=s)
            printf("1\n");
        else if(total==(s*3))
            printf("3\n");
        else
            printf("2\n");
        t--;
    }
    return 0;
}

/*
int ans=0,count1=0,total1=0;
        for(int j=0; j<3; j++){
            total1 = total1 + w[j];
            if(total1 == s){
                total1 = 0;
                count1++;
            }
            if(total1 > s){
                total1 = total1 - w[j];
                count1++;
            }
            if(total1<s){
                count1++;
            }
        }
        if(total1>0){
            count1++;
        }

        int count2=0,total2=0;
        for(int k=2; k>=0; k--){
            total2 = total2 + w[k];
            if(total2 == s){
                total2 = 0;
                count2++;
            }
            if(total1 > s){
                total2 = total2 - w[k];
                count2++;
            }
            if(total2<s){
                count2++;
            }
        }
        if(total2>0){
            count2++;
        }


        if(count1 <= count2){
            ans = count1;
        }else if(count2 < count1){
            ans = count2;
        }

        
        printf("%d\n",ans);
*/