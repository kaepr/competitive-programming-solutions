#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,a,b;
    cin>>n>>m>>a>>b;
    /*
    n - total times
    m - total b rides
    b - price of 1 m ride
    a - normal price
    */
    if(m*a <=b)
        cout<<n*a<<"\n";
    else
        cout<<(n/m)*b + min((n%m)*a, b)<<"\n";

    
    return 0;
}