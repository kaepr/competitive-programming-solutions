#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        int l,r,cnt=1,elm;
        elm = arr[i];


        if(i == 0)
            l=0;
        else
            l=i-1;

        if(i == n-1)
            r=n-1;
        else
            r=i+1;

        //left side
        if(i!=0){
            int new_elm=arr[i];
            for(int j=l; j>=0; j--){
                if(arr[j]>new_elm){
                    break;
                }else{
                    cnt++;
                    new_elm = arr[j];
                }
            }
        }
        

        //right side
        if(i!=n-1){
            int new_elm = arr[i];
            for(int j=r; j<n; j++){
                if(arr[j]>new_elm){
                    break;
                }else{
                    new_elm = arr[j];
                    cnt++;
                }
            }
        }
        ans=max(cnt,ans);
    }
    cout<<ans<<"\n";
    return 0;
}