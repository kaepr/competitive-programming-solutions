//http://codeforces.com/contest/1325/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)  
{  
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
}  
  
// Function to return LCM of two numbers  
ll lcm(ll a, ll b)  
{  
    return (a*b)/gcd(a, b);  
} 

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        ll x;
        scanf("%lld",&x);
        //printf("%lld\n",x);
        ll a=1;
        ll b = x-1;
        int sol=0;
        while(sol==0){
            if(gcd(a,b) + lcm(a,b) == x){
                printf("%lld %lld\n",a,b);
                sol=1;
            }else{
                a++;
                b--;
            }
        }
    }
    return 0;
}