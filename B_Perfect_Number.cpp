#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int sum(int num){
    int ans = 0;
    while(num){
        ans += num % 10;
        num /= 10;
    }
    return ans;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin>>k;
    int num=0;
    while(k){
        num++;
        if(sum(num)==10)
            k--;
    }
    cout<<num<<"\n";

      
    return 0;
}