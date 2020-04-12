#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int arr[n];
        vector<int> rem;
        int D=0;
        int a = n/4;
        int x = n-a;
        if(x%3==0){
            D = (x)/3 + a;
        }

        if(x%3==1){
            D = (x)/3 + a;
        }
        
        if(x%3== 2){
            D = (x)/3 + a + 1;
        }

        int cnt=0,last_num=0;
        printf("%d\n",D);
        for(int i=1; i<=n; i++){
            if(i%4 == 0){
                rem.push_back(i);
                continue;
            }
            cnt++;
            printf("%d ",i);
            if(cnt%3==0){
                printf("\n");
            }
            last_num = i;
        }
        if(x%3==0){
            printf("\n");
        }
        //add remaining numbers
        int print_flag=1;
        for(int i=4; i<= n; i=i+4){
            if(x%3==0){
                printf("%d",i);
            }else if(x%3==1 && print_flag){
                if(__gcd(last_num, i) == 1){
                    printf("%d",i);
                }
                //printf("\n");
                print_flag=0;
            }else if(x%3 == 2){
                printf("\n%d",i);
                x=3;
            }
            
        }

        t--;
    }
    return 0;
}