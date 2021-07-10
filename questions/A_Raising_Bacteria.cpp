#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int cnt = 0;
    while(n>0){
        if(n&1==1)
            cnt++;
        n = n>>1;
    }
    cout<<cnt<<"\n";

    return 0;
}