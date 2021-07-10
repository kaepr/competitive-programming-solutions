#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int t;
    cin>>t;
    while(t>0){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout << 0 << endl;
        }else if(a>b){
            if((a-b)%2==0)
                cout << 1 << endl;
            else if((a-b)%2 != 0)
                cout << 2 << endl;
        }else if(b>a){
            if((b-a)%2==0)
                cout << 2 << endl;
            else if((b-a)%2 != 0)
                cout << 1 << endl;
        }
        t--;
    }
    return 0;
}