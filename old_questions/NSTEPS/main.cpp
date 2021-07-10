#include <bits/stdc++.h>
using namespace std;

int odd(int x){
    if(x%2 == 0){
        return 0;
    }
    return 1;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        int x,y;
        scanf("%d%d",&x,&y);
        int a = odd(x);
        
        if(x==y && a==0){
            cout << x+y << "\n";
        }

        if(x==0 && y==0){
            cout << 0 << "\n";
        }
        
        if(x==1 && y==1){
            cout << 1 << "\n";
        }
        
        if(x==y && a==1){
            cout << x + y - 1 << "\n";
        }
        
        if(x-y==2 && a==0){
            cout << x + y << "\n";
        }
        
        if(x-y==2 && a==1){
            cout << x + y - 1 << "\n";
        }

        if(y>x){
            cout << "No Number" << "\n";
        }
        
        if(x-y != 2){
        	cout << "No Number" << "\n";
        }
        
        t--;
    }
    return 0;
}