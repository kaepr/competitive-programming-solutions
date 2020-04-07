#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b[n];
    int bc[n];
    for(int i=0; i<n; i++){
        cin>>b[i];
        bc[i] = b[i];
    }
    sort(b,b+n);
    if(n==1){
        cout<<b[0]<<endl;
    }
    int temp=0;
    int highest = 0;
    for(int i=0; i<n; i++){
        if(b[i+1] - b[i] == binary_search(bc,bc+n,b[i+1]) - binary_search(bc,bc+n,b[i]) && i<n-1){
            temp = temp + b[i];
        }else if(b[i] - b[i-1] == binary_search(bc, bc+n, b[i]) - binary_search(bc, bc+n, b[i-1])){
            temp = temp + b[i];
            if(temp > highest){
                highest = temp;
                temp = 0;
            }

        }
    }
    if(highest==0){
        cout<<0<<endl;
    }else
    {
        cout<<highest<<endl;
    }
    

    return 0;
}