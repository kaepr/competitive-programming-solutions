#include <bits/stdc++.h>
using namespace std;

 

int main(){
    int n;
    cin>>n;
        
    int a[n];
    int b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
       

    for(int i=0; i<n; i++)
        cin>>b[i];

    int flag=1;
    for(int i=0; i<n; i++){
        if(a[i] != b[i])
            flag = 0;
    }

    

    if(flag == 1){
        cout<<-1<<endl;
        return 0;
    }

    int a_sum=0;
    int b_sum=0;
    for(int i=0; i<n; i++){
        a_sum = a_sum + a[i];;
    }

    for(int i=0; i<n; i++){
        b_sum = b_sum + b[i];;
    }

    if(b_sum == 0){
        cout<<1<<endl;
        return 0;
    }

    if(a_sum == 0){
        cout<<-1<<endl;
        return 0;
    }

    int a_win=0;
    int b_win=0;
    for(int i=0; i<n; i++){
        if(a[i]==1 && b[i]==0){
            a_win++;
        }else if(a[i]==0 && b[i]==1){
            b_win++;
        }
    }
    if(a_win==0){
        cout<<-1<<endl;
        return 0;
    }
    int ans = b_win/a_win + 1;
    cout << ans << endl;
    return 0;
}