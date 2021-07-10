#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int check(int n){
    while(n > 0){
        int digit = n%10;
        if(digit==1){
            return true;
        }
        n/=10;
    }
    return false;
}

int calc(int n){
    int ans = 1;
    while(n>0){
        int digit = n%10;
        ans *= digit;
        n/=10;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}