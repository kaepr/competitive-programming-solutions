CP#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;
    cin>>a>>b;
    int t=0;
    while(a>0 && b>0){
        if(a==1 && b==1){
            //do nothing
            break;
        }else if(a<=b){
            //b greater
            b-=2;
            a++;
            t++;
        }else if(b<a){
            //a greater
            a-=2;
            b++;
            t++;
        }
        //cout<<"a is "<<a<<"b is "<<b<<"\n";
    }
    cout<<t<<"\n";
     
    return 0;
}