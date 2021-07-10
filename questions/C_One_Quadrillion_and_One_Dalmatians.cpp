#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> vec;
    while(n > 0){
        n--;
        vec.push_back(n%26);
        n /= 26;
    }
    for(ll i=vec.size() - 1; i>=0; i--){
        cout<<string(1, 'a' + vec.at(i));
    }



   
    return 0;
}