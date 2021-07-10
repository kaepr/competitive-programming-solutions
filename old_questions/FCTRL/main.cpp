#include <bits/stdc++.h>
using namespace std;

long long trailingzeroes(long long n){
    long long ans=0,i=1,x=n;
    while(x>0){
        x = (int)(n / ((int)(pow(5,i))));
        ans = ans + x;
        i++;
    }
    return ans;
}

int main(){
    long long t;
    cin >> t;
    long long a=0,n=0;
    while(t>0){
        cin >> n;
        a = trailingzeroes(n);
        cout << a;
        t--;
        cout << "\n";
    }
    return 0;
}